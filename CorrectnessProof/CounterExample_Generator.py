import os

def create_prompt(initial_prompt, prev_output, counterexamples):
    prompt = f"""
    {initial_prompt}
    
    Assistant:
    {prev_output}
    
    Human:
    That is incorrect on the following inputs:
    #Counterexamples
    //Enter counterexamples here.
    {counterexamples}
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

if __name__ == "__main__":
    main()
