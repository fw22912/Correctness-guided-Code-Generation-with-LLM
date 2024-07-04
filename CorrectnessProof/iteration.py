import argparse
import Gemini
import cbmc_call
import os
import Prompt_Generator as prompt_generator
import CounterExample_Generator as counter_example_generator


def main(file_path):
    # initial_prompt = prompt_genertator.main(file_path
    #Feed the prompt to the LLM and feed it into cbmc
    file_name = os.path.splitext(os.path.basename(file_path))[0]
    prompt = prompt_generator.create_prompt(file_path)
    # initial_prompt = prompt
    while True:
        response_text = Gemini.main(prompt, file_path)
        reiteration = cbmc_call.main(file_path)
        if reiteration:
            print(reiteration)
            print("Verification successful")
            break
        else:
            print("Verification Failed. Retrying with a new prompt with counter examples...")
            counter_examples = cbmc_call.cbmc_result_parsing(file_name=file_name)
            prompt = counter_example_generator.create_prompt(prompt, response_text, counterexamples=counter_examples)
            print("New Prompt Generated:" + prompt)



if __name__=="__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("file_path", type=str)
    args = parser.parse_args()
    main(args.file_path)