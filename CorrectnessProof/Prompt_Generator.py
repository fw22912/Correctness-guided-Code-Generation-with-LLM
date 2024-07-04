import os
import argparse

def read_c_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    return content

def create_prompt(file_content):
    query_code = file_content

    prompt = f"""
# Preamble
You are given a C program. We need to create a proof harness function.

# Code generation example
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
Q: Write method 'void proof_harness()' that tests all the methods below for all possible inputs.

{query_code}


# Constraints
    Here are some constraints that you should respect:
    - Give me only the translated code, don't add explanations or anything else. 
    - Use only safe C.
    - Do not use custom generics. # fuzzer limitation
    - Do not remove any code from the original code you have received.
    - Ensure that all libraries needed are declared.
    """

    return prompt

def clean_code(response_text):
    cleaned_text = response_text.replace('```c', '').replace('```', '').strip()
    return cleaned_text

def main(file_path):
    print("Running Gemini...")
    file_content = read_c_file(file_path)
    prompt = create_prompt(file_content)
    print(prompt)

    return prompt


