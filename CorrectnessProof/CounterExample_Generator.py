import os

def create_prompt(file_content, prev_output, counterexamples):
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
    
    Q: You are given the original C code file, previous output, and the counter examples. Your job is to improve the 
    incorrect methods only based on the provided counter exmaples.
    
    #Original C code:
    
    {file_content}
    
    
    #Assistant's previous response:
    {prev_output}
    
    
    That is incorrect on the following inputs:
    #Counterexamples
    {counterexamples}
    
# Constraints
    Here are some constraints that you should respect:
    - Give me only the translated code, don't add explanations or anything else. 
    - Use only safe C.
    - Do not use custom generics. # fuzzer limitation
    - Do not remove any code from the original code you have received.
    - Ensure that <assert.h> is declared when using assert. 
    """

    return prompt

def clean_code(response_text):
    cleaned_text = response_text.replace('```c', '').replace('```', '').strip()
    return cleaned_text

def main(file_content, prev_output, counterexamples):
    prompt = create_prompt(file_content, prev_output, counterexamples)
    prompt = clean_code(prompt)
    print(prompt)

    return prompt

# if __name__ == "__main__":
#     main()
