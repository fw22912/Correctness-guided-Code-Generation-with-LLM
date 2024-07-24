import os

def create_prompt(file_content, prev_output, counterexamples):
    prompt = f"""
     # Preamble
    You are given the original C code file, previous output, and the counter examples. Your job is to improve the 
    incorrect methods only based on the provided counter examples.
    
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
    - Ensure that all libraries needed, including <assert.h> and <stdbool.h>, are declared at the beginning of the code.
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
