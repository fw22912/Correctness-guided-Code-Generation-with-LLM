import json
import subprocess
import os
import Gemini as gemini
import argparse
import CounterExample_Generator as cg

def run_cbmc(file_path, harness_method_list):
    # file = open(file_path, 'w+')
    output_path = 'CBMC_Result'
    original_file_name = os.path.splitext(os.path.basename(file_path))[0]
    harness_file_name = original_file_name + "_with_harness.c"
    cbmc_output_file = os.path.join(output_path, original_file_name + "_cbmc.json")

    harness_command = "".join(["--function " + method + " " for method in harness_method_list])

    print("Command: " + harness_command)
    print(f'cbmc Proof_Harness/{harness_file_name} {harness_command} --unwind 5 --trace --json-ui')

    with open(cbmc_output_file, 'w+') as file:
        subprocess.run(f'cbmc Proof_Harness/{harness_file_name} {harness_command} --unwind 5 --trace --json-ui', shell=True, stdout=file)

    return cbmc_output_file


def cbmc_verification_status(file_name):
    cbmc_result_file = "CBMC_Result/" + file_name + "_cbmc.json"
    cbmc_result_file = "CBMC_Result/" + file_name + "_cbmc.json"
    print("CBMC FILE Path: " + cbmc_result_file)
    with open(cbmc_result_file, 'r') as file:
        data = json.load(file)
        for item in data:
            if 'cProverStatus' in item:
                print("=================STATUS=================")
                print(item['cProverStatus'])
                if item['cProverStatus'] == 'success': return True
                else: return True
    # return True


def create_couter_example_prompt(original_code, prev_output, counter_examples):
    counter_prompt = cg.main(original_code, prev_output, counter_examples)
    return counter_prompt

def main(file_path, harness_method_list):
    file_name = os.path.splitext(os.path.basename(file_path))[0]
    # gemini.main(file_path)
    print("Running CBMC...")
    run_cbmc(file_path, harness_method_list)
    reiteration = cbmc_verification_status(file_name)
    return reiteration
