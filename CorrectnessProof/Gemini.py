import google.generativeai as genai
import os
import argparse
import Prompt_Generator as pg
import re

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
    harness_function = re.search(r'void proof_harness\(\) {[^}]*}', response_text, re.MULTILINE | re.DOTALL)
    if harness_function:
        return harness_function.group(0)
    else:
        raise ValueError("No proof_harness function found.")


def generate_file(cleaned_text, original_file_path):
    file_name = os.path.splitext(os.path.basename(original_file_path))[0]
    harness_file_name = os.path.join(base_dir, file_name + "_with_harness.c")

    os.makedirs(base_dir, exist_ok=True)
    with open(harness_file_name, 'w') as f:
        f.write(cleaned_text)


def generate_harness_file(cleaned_text, original_file_path):
    file_name = os.path.splitext(os.path.basename(original_file_path))[0]
    harness_file_name = os.path.join(base_dir, file_name + "_only_harness.c")

    os.makedirs(base_dir, exist_ok=True)

    with open(harness_file_name, 'w') as f:
        f.write(cleaned_text)


def main(file_path):
    configure_genai(api_key=os.environ['GENAI_API_KEY'])
    prompt = generate_prompt(file_path)
    response_text = generate_content(prompt)
    print(response_text)
    # Extracting texts
    cleaned_text = clean_code(response_text)
    harness_function = extract_harness(response_text)
    # Saving them into a file
    generate_file(cleaned_text, file_path)
    generate_harness_file(harness_function, file_path)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("file_path", type=str)
    args = parser.parse_args()
    main(args.file_path)
