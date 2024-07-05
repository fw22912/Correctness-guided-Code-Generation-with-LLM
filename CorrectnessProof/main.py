import argparse
import Gemini
import cbmc_call
import os
import Prompt_Generator as prompt_generator
import CounterExample_Generator as counter_example_generator


def generate_proof_harness(method_list):
    return ["proof_harness_" + method for method in method_list]

def main(file_path):
    file_name = os.path.splitext(os.path.basename(file_path))[0]
    prompt, method_list = prompt_generator.main(file_path)
    harness_list = generate_proof_harness(method_list)

    while True:
        try:
            response_text = Gemini.main(prompt, file_path, method_list)
            reiteration = cbmc_call.main(file_path, harness_list)

            if reiteration == True:
                print("Verification successful")
                break
            else:
                print("Verification Failed. Retrying with a new prompt with counterexamples...")
                counter_examples = None
                prompt = counter_example_generator.create_prompt(prompt, response_text, counterexamples=counter_examples)
                print(f"New Prompt Generated:\n{prompt}")
        except Exception as e:
            print(f"An unexpected error occurred: {e}")
            break


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("file_path", type=str)
    args = parser.parse_args()
    main(args.file_path)
