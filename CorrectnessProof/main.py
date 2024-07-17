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


def main(file_path):
    file_name = os.path.splitext(os.path.basename(file_path))[0]
    print("\nFile name: " + file_name + ".c")
    prompt, method_list, file_content = prompt_generator.main(file_path)
    # harness_list = extract_harness_name(file_content)

    # print(harness_list)
    cnt = 0

    while True:
        try:
            response_text = Gemini.main(prompt, file_path, method_list)
            harness_list = extract_harness_name(response_text)
            print("harness list: ", harness_list)
            # print("Response Text:  \n", response_text)

            reiteration, parse = cbmc_call.main(file_path, harness_list)
            print(parse) #parse[0] is either 'syntax' or 'result',
            if reiteration:
                print("Verification successful\n")
                break
            elif cnt > 1:
                print("Verification failed. Moving on to the next example...\n")
                break
            else:
                print("Verification Failed. Retrying with a new prompt with counterexamples...\n")
                cnt += 1
                # counter_examples = None
                # prompt = counter_example_generator.create_prompt(file_content, response_text, counterexamples=counter_examples)
                # print(f"New Prompt Generated:\n{prompt}")
        except Exception as e:
            print(f"An unexpected error occurred: \n{e}")
            break


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("file_path", type=str)
    args = parser.parse_args()
    main(args.file_path)
