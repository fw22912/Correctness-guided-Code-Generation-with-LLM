import os

def create_prompt(file_content, prev_output, counterexamples):
    query_code = file_content

    prompt = f"""
    Human: 
    
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
    void proof_harness_withdraw() {{ 
        struct Account *account;
        int amount;
        CPROVER_assume(account->bal >= 0);
        CPROVER_assume(amount > 0);
        CPROVER_assume(account->bal >= amount);

        // Save the initial balance for verification 
        unsigned short initial_balance = account->bal;
        withdraw(account, amount);

        // Check that the new balance is the expected value after withdrawal
        assert(account->bal == initial_balance - amount); 
    }}

    # Instruction
    Give me a proof harness code of the below C code.

    # Query
    Q: Write method "void proof_harness_newNode()" that tests method transfer below for all possible inputs.

    {query_code}

    # Constraints
    Here are some constraints that you should respect:
    - Give me only the translated code, don't add explanations or anything else. 
    - Use only safe C.
    - Do not use custom generics. # fuzzer limitation
    - Ensure there is an entry point in main.
    
    Assistant:
    {prev_output}
    
    Human:
    That is incorrect on the following inputs:
    #Counterexamples
    //Input counterexamples here.
    {counterexamples}
    """

    return prompt

def main(file_content, prev_output, counterexamples):
    prompt = create_prompt(file_content, prev_output, counterexamples)
    print(prompt)

    return prompt

if __name__ == "__main__":
    main()
