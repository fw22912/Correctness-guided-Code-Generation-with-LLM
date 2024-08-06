import argparse
import Gemini
import cbmc_call
import os
import sys
import Prompt_Generator as prompt_generator
import re
import CounterExample_Generator as counter_example_generator


# def generate_proof_harness(method_list):
# return ["proof_harness_" + method for method in method_list]


def extract_harness_name(file_content):
    function_pattern = re.compile(r'\b[a-zA-Z_]\w*\s+\*?\b(proof_harness_\w*)\s*\([^)]*\)\s*\{')
    matches = function_pattern.findall(file_content)

    method_names = [match for match in matches if match not in {"main", "if", "for", "while"}]

    return method_names


def enumerate_c_code(code_with_harness):
    # Split the input C code string into individual lines
    lines = code_with_harness.strip().split('\n')

    # Enumerate each line and format it with line numbers
    enumerated_lines = [f'{i + 1}: {line}' for i, line in enumerate(lines)]

    last_line_number = len(lines)

    # Join the enumerated lines back into a single string with newline characters
    formatted_code = '\n'.join(enumerated_lines)
    return formatted_code, last_line_number


def find_line_number(log_message):
    # Regular expression to find the word 'line' followed by a number
    match = re.search(r'line (\d+)', log_message)

    if match:
        # Return the number found after 'line' as an integer
        return int(match.group(1))
    else:
        # Return None if no match is found
        return None

def remove_comments_from_file(file_path):
    # Read the contents of the file
    with open(file_path, 'r') as file:
        code = file.read()

    # Regular expressions for comments
    block_comment_re = re.compile(r'/\*.*?\*/', re.DOTALL)
    single_line_comment_re = re.compile(r'//.*')

    # Remove block comments
    def remove_block_comments(code):
        while True:
            match = block_comment_re.search(code)
            if not match:
                break
            # Check for edge case: //* standard C - to octal */
            if match.start() > 0 and code[match.start() - 1] == '/':
                code = code[:match.start() - 1] + code[match.end():]
            else:
                code = code[:match.start()] + code[match.end():]
        return code

    code = remove_block_comments(code)
    # Remove single-line comments
    code = single_line_comment_re.sub('', code)

    # Write the cleaned code back to the file
    with open(file_path, 'w') as file:
        file.write(code)

def main_retry_non_det(file_path):
    Gemini.configure_genai(api_key=os.environ['GENAI_API_KEY'])
    file_name = os.path.splitext(os.path.basename(file_path))[0]

    remove_comments_from_file(file_path)

    print("\nFile name: " + file_path)
    prompt, method_list, file_content = prompt_generator.main(file_path)

    gemini_output_code_with_harness, gemini_output_code_only_harness = Gemini.main(prompt)

    enumerate_original_c_code, original_c_code_last_line_number = enumerate_c_code(file_content)
    cnt = 0
    response_text = gemini_output_code_with_harness

    last_error_reason_for_failure = 'Passed 1st try'
    while True:
        try:
            enumerated_response_text, last_line_number = enumerate_c_code(response_text)

            harness_list = extract_harness_name(response_text)
            print("harness list: ", harness_list)

            reiteration, counter_examples, current_error_reason_for_failure = cbmc_call.main(file_path, response_text,
                                                                                             harness_list)

            if current_error_reason_for_failure == 'file not found':
                return cnt, 'error', 'file not found'
            elif current_error_reason_for_failure == 'cbmc took too long to run':
                return cnt, 'error', 'cbmc took too long to run'

            if last_line_number > 1000:
                return cnt, 'error', 'gemini stops generating after 1000 lines of code'

            if reiteration:
                print("Verification successful\n")

                return cnt, 'success', last_error_reason_for_failure
            elif cnt == 2:
                print("Verification failed. Moving on to the next example...\n")
                return cnt, 'fail', last_error_reason_for_failure
            else:
                # print(enumerated_response_text)
                print("Verification Failed. Retrying with a new prompt with counterexamples...\n")
                cnt += 1
                print(counter_examples)
                line_number_of_error = find_line_number(counter_examples)
                if line_number_of_error <= original_c_code_last_line_number:
                    return cnt, 'error', 'syntax error in original c code'


            last_error_reason_for_failure = current_error_reason_for_failure

        except Exception as e:
            print(f"An unexpected error occurred: \n{e}")
            return cnt, 'error', str(e)

def main(file_path):
    Gemini.configure_genai(api_key=os.environ['GENAI_API_KEY'])
    file_name = os.path.splitext(os.path.basename(file_path))[0]

    remove_comments_from_file(file_path)

    print("\nFile name: " + file_path)
    prompt, method_list, file_content = prompt_generator.main(file_path)

    gemini_output_code_with_harness, gemini_output_code_only_harness = Gemini.main(prompt)

    enumerate_original_c_code, original_c_code_last_line_number = enumerate_c_code(file_content)
    cnt = 0
    response_text = gemini_output_code_with_harness

    last_error_reason_for_failure = 'Passed 1st try'
    while True:
        try:
            enumerated_response_text, last_line_number = enumerate_c_code(response_text)

            harness_list = extract_harness_name(response_text)
            print("harness list: ", harness_list)

            reiteration, counter_examples, current_error_reason_for_failure = cbmc_call.main(file_path,response_text, harness_list)

            if current_error_reason_for_failure == 'file not found':
                return cnt, 'error', 'file not found'
            elif current_error_reason_for_failure == 'cbmc took too long to run':
                return cnt, 'error', 'cbmc took too long to run'

            if last_line_number > 1000:
                return cnt, 'error', 'gemini stops generating after 1000 lines of code'

            if reiteration:
                print("Verification successful\n")

                return cnt,'success', last_error_reason_for_failure
            elif cnt == 2:
                print("Verification failed. Moving on to the next example...\n")
                return cnt, 'fail', last_error_reason_for_failure
            else:
                #print(enumerated_response_text)
                print("Verification Failed. Retrying with a new prompt with counterexamples...\n")
                cnt += 1
                print(counter_examples)
                line_number_of_error = find_line_number(counter_examples)
                if line_number_of_error <= original_c_code_last_line_number:
                    return cnt, 'error', 'syntax error in original c code'

                prompt = counter_example_generator.create_prompt(file_content, enumerated_response_text, counter_examples)

            response_text, gemini_output_code_only_harness = Gemini.main(prompt)

            last_error_reason_for_failure = current_error_reason_for_failure

        except Exception as e:
            print(f"An unexpected error occurred: \n{e}")
            return cnt, 'error', str(e)


def repeated_file_paths(args):
    count = 0
    for i in args.file_paths:
        main(args.file_paths[count])
        count += 1

def repeated_file_paths_for_spamming(args):
    count = 0
    for i in args.file_paths:
        main_retry_non_det(args.file_paths[count])
        count += 1


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("file_paths", nargs='+', type=str, help="List of file paths to process")
    args = parser.parse_args()
    repeated_file_paths(args)



