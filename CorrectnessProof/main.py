import argparse
import Gemini
import cbmc_call
import os
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

    # Join the enumerated lines back into a single string with newline characters
    return '\n'.join(enumerated_lines)


def main(file_path):
    Gemini.configure_genai(api_key=os.environ['GENAI_API_KEY'])
    file_name = os.path.splitext(os.path.basename(file_path))[0]

    print("\nFile name: " + file_name + ".c")
    prompt, method_list, file_content = prompt_generator.main(file_path)
    # harness_list = extract_harness_name(file_content)
    gemini_output_code_with_harness, gemini_output_code_only_harness = Gemini.main(prompt, file_path, method_list)
    # print(harness_list)
    cnt = 0
    response_text = gemini_output_code_with_harness
    harness_list = extract_harness_name(gemini_output_code_with_harness)
    last_counter_example = ''
    while True:
        # try:

            enumerated_response_text = enumerate_c_code(response_text)
            print("harness list: ", harness_list)
            # print("Response Text:  \n", response_text)
            #print(response_text)
            reiteration, counter_examples = cbmc_call.main(file_path,response_text, harness_list)

            #print(parse) #parse[0] is either 'syntax' or 'result',
            if reiteration:
                print("Verification successful\n")
                break
            elif cnt == 3:
                print("Verification failed. Moving on to the next example...\n")
                break
            else:
                print("Verification Failed. Retrying with a new prompt with counterexamples...\n")
                cnt += 1
                print(counter_examples)
                print(enumerated_response_text)
                #if counter_examples == last_counter_example:
                #    print('Gemini has failed fix the harness')
                #    break

                prompt = counter_example_generator.create_prompt(file_content, enumerated_response_text, counter_examples)
                last_counter_example = counter_examples
                #print(f"New Prompt Generated:\n{prompt}")

            response_text, gemini_output_code_only_harness = Gemini.main(prompt, file_path, method_list)

        # except Exception as e:
        #     print(f"An unexpected error occurred: \n{e}")
        #     break


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("file_path", type=str)
    args = parser.parse_args()
    main(args.file_path)
