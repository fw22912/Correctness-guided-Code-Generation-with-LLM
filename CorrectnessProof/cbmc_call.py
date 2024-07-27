import json
import subprocess
import os
import Gemini as gemini
import argparse
import CounterExample_Generator as cg
import cbmc_parsing


def run_cbmc(file_path, harness_method_list): ## this bit is needed in case the json file is too large to store in a string?
    import os
    import subprocess

    output_path = 'CBMC_Result'
    original_file_name = os.path.splitext(os.path.basename(file_path))[0]
    harness_file_name = original_file_name + "_with_harness.c"
    cbmc_output_file = os.path.join(output_path, original_file_name + "_cbmc.json")

    harness_command = " ".join([f"--function {method}" for method in harness_method_list])


    command_str = f'cbmc Proof_Harness/{harness_file_name} --function combined_proof_harness --no-standard-checks --no-malloc-may-fail --verbosity 8 --unwind 3 --trace --json-ui'
    print(command_str)

    try:
        result = subprocess.run(command_str,
        shell=True, capture_output=True, text=True)

        cbmc_json_string = result.stdout

        return cbmc_json_string
    except Exception as e:
        print(f"An unexpected error occurred, likely because the json file storing the output was too big for the string. This program will proceed now by storing it in a file : {e}")
        with open(cbmc_output_file, 'w+') as file:
            subprocess.run(command_str, shell=True, stdout=file)
        return cbmc_output_file



def cbmc_string_or_file(query_string): #leave for later, assume string for now
    if "_cbmc.json" in query_string:
        return 'file'
    else:
        return 'string'

def cbmc_verification_status(file_name):
    # cbmc_result_file = "CBMC_Result/" + file_name + "_cbmc.json"
    cbmc_result_file = "CBMC_Result/" + file_name + "_cbmc.json"
    print("CBMC FILE Path: " + cbmc_result_file)
    with open(cbmc_result_file, 'r') as file: ###############
        data = json.load(file) ###############
    for item in data:
        if 'cProverStatus' in item:
            print("=================STATUS=================")
            print(item['cProverStatus'])
            if item['cProverStatus'] == 'success':
                return True
            else:
                return False

    return False
    # return True


def create_counter_example_prompt(original_code, prev_output, counter_examples):
    counter_prompt = cg.main(original_code, prev_output, counter_examples)
    return counter_prompt


def main(file_path, total_code_with_harnesses, harness_method_list): #expects the original file path and harness method list
    file_name = os.path.splitext(os.path.basename(file_path))[0]
    # gemini.main(file_path)


    print("Running CBMC...")
    cbmc_output = run_cbmc(file_path, harness_method_list) ###############under the current assumption that the json string isn't too big


    method_list = [item.replace('proof_harness_', '') for item in harness_method_list]
    #print(method_list)

    parse = cbmc_parsing.main(cbmc_output, total_code_with_harnesses, method_list)

    reiteration = cbmc_verification_status(file_name)
    return reiteration, parse
