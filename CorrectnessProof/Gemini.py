import google.generativeai as genai
import os
import argparse
import Prompt_Generator as pg
import re
import inspect

base_dir = "/Users/hyoyeon/Desktop/UNI/Faculty Internship/Correctness-guided-Code-Generation-with-LLM/CorrectnessProof/Proof_Harness"


def configure_genai(api_key):
    genai.configure(api_key=api_key)


def generate_prompt(file_path):
    return pg.main(file_path)


def generate_content(prompt):
    model = genai.GenerativeModel('gemini-1.5-flash')
    response = model.generate_content(prompt)
    return response.text


def clean_code(response_text):
    cleaned_text = response_text.replace('```c', '').replace('```', '').strip()
    return cleaned_text


def extract_harness(response_text):
    harness_functions = re.findall(r'void\s+\w*proof_harness\w*\s*\(\s*\)\s*{[^}]*}', response_text, re.MULTILINE | re.DOTALL)
    if harness_functions:
        unique_harness_functions = list(set(harness_functions))  # removing duplicates
        unique_harness_functions_with_newline = [func + '\n' + '\n' for func in unique_harness_functions]
        return unique_harness_functions_with_newline
    raise ValueError("No function containing 'proof_harness' in its name found.")


def generate_file(cleaned_text, original_file_path):
    file_name = os.path.splitext(os.path.basename(original_file_path))[0]
    harness_file_name = os.path.join(base_dir, file_name + "_with_harness.c")

    os.makedirs(base_dir, exist_ok=True)
    with open(harness_file_name, 'w') as f:
        f.write(cleaned_text)


def generate_harness_file(harness_functions, original_file_path):
    file_name = os.path.splitext(os.path.basename(original_file_path))[0]
    harness_file_name = os.path.join(base_dir, file_name + "_only_harness.c")

    os.makedirs(base_dir, exist_ok=True)

    with open(harness_file_name, 'w') as f:
        for func in harness_functions:
            f.write(func)


def main(prompt, file_path, method_list):
    configure_genai(api_key=os.environ['GENAI_API_KEY'])
    # prompt = generate_prompt(file_path)
    print("Running Gemini-Flask...")
    response_text = generate_content(prompt)

    cleaned_text = clean_code(response_text)
    harness_function = extract_harness(response_text)

    generate_file(cleaned_text, file_path)
    generate_harness_file(harness_function, file_path)

    return cleaned_text
