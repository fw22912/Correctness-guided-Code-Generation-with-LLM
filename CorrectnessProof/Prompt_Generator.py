import os
import argparse
import re

def read_c_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    return content

def create_prompt(file_content):
    query_code = file_content

    prompt = f"""
   # Preamble
    You are given a C program. We need to create a proof harness function.
    # Code generation example - You are given three examples.

    Q: Write a method "void proof_harness_withdraw()" that tests method withdraw below for all possible inputs.

    // Define the Account structure
    struct Account {{
        unsigned short bal;
    }};

    // Function to withdraw an amount from an account
    void withdraw(struct Account *account, unsigned short amount) {{ 
        unsigned short de = account->bal;
        account->bal = de - amount; 
    }}

    A:
    struct Account {{
    unsigned short bal;
        }};
    
    
    void withdraw(struct Account *account, unsigned short amount) {{
        unsigned short de = account->bal;
        account->bal = de - amount;
    }}
    
    void proof_harness_withdraw() {{
        struct Account *account = (struct Account *)malloc(sizeof(struct Account));
        __CPROVER_assume(account != NULL);  // Ensure account is not NULL
    
        unsigned short amount;
    
        __CPROVER_assume(account->bal >= 0);
        __CPROVER_assume(amount > 0);
        __CPROVER_assume(account->bal >= amount);
    
        unsigned short initial_balance = account->bal;
    
        withdraw(account, amount);
        assert(account->bal == initial_balance - amount);
    
        free(account);
    }}


    # Instruction
    Give me a proof harness code of the below C code.

    # Query 
    Q: Write method "void proof_harness_{{function_name}}()" that tests every methods including 'main()' 
    below for all possible inputs. Then write a method "void combined_proof_harness()" that calls every other proof 
    harness methods generated. 
    
    {query_code}.

    # Constraints
    Here are some constraints that you should respect:
    - Give me only the translated code, don't add explanations or anything else. 
    - Use only safe C.
    - Do not use custom generics. # fuzzer limitation
    - Do not remove any code from the original code you have received.
    - Ensure that all libraries needed, including <assert.h> and <stdbool.h>, are declared at the beginning of the code.
    """

    return prompt

def clean_code(response_text):
    cleaned_text = response_text.replace('```c', '').replace('```', '').strip()
    return cleaned_text


def extract_method_name(file_content):
    # Regex to match C function definitions
    function_pattern = re.compile(r'\b[a-zA-Z_]\w*\s+\*?\b[a-zA-Z_]\w*\s*\([^)]*\)\s*\{')
    matches = function_pattern.findall(file_content)

    method_names = []
    for match in matches:
        # Extract the method name from the match
        method_name = re.search(r'\b[a-zA-Z_]\w*\s+\*?\b([a-zA-Z_]\w*)\s*\(', match).group(1)
        if method_name not in {"main", "if", "for", "while"}:
            method_names.append(method_name)

    # print(method_names)
    return method_names


def main(file_path):
    print("Reading files and generating prompts...")
    file_content = read_c_file(file_path)
    prompt = create_prompt(file_content)
    file_list = extract_method_name(file_content)

    return prompt, file_list, file_content


