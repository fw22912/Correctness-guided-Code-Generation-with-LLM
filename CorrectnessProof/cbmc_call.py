import json
import subprocess
import os
import Gemini as gemini
import argparse
import CounterExample_Generator as cg
import cbmc_parsing


def run_cbmc(file_path, harness_method_list):
    import os
    import subprocess

    output_path = 'CBMC_Result'
    original_file_name = os.path.splitext(os.path.basename(file_path))[0]
    harness_file_name = original_file_name + "_with_harness.c"
    cbmc_output_file = os.path.join(output_path, original_file_name + "_cbmc.json")

    #harness_command = " ".join([f"--function {method}" for method in harness_method_list])
    method = harness_method_list[0]
    harness_command = " ".join([f"--function {method}" ])
    # print("Command: " + harness_command)
    #this bit calls the files in one go
    print(f'cbmc Proof_Harness/{harness_file_name} {harness_command} --no-standard-checks --no-malloc-may-fail --verbosity 8 --unwind 3 --trace --json-ui')

    cbmc_output_str = subprocess.check_output(f'cbmc Proof_Harness/{harness_file_name} {harness_command} --no-standard-checks --no-malloc-may-fail --verbosity 8 --unwind 3 --trace --json-ui', shell=True, text=True)

    #with open(cbmc_output_file, 'w+') as file:
     #   subprocess.run(f'cbmc Proof_Harness/{harness_file_name} {harness_command} --no-standard-checks --no-malloc-may-fail --verbosity 8 --unwind 3 --trace --json-ui',
      #                 shell=True, stdout=file)

    return cbmc_output_str



def cbmc_verification_status(file_name):
    # cbmc_result_file = "CBMC_Result/" + file_name + "_cbmc.json"
    cbmc_result_file = "CBMC_Result/" + file_name + "_cbmc.json"
    print("CBMC FILE Path: " + cbmc_result_file)
    with open(cbmc_result_file, 'r') as file:
        data = json.load(file)
        for item in data:
            if 'cProverStatus' in item:
                print("=================STATUS=================")
                print(item['cProverStatus'])
                if item['cProverStatus'] == 'success':
                    return True
                else:
                    return False

    # return True


def create_couter_example_prompt(original_code, prev_output, counter_examples):
    counter_prompt = cg.main(original_code, prev_output, counter_examples)
    return counter_prompt


def main(file_path, harness_method_list):
    file_name = os.path.splitext(os.path.basename(file_path))[0]
    # gemini.main(file_path)
    print("Running CBMC...")
    cbmc_output = run_cbmc(file_path, harness_method_list)
    with open(file_path + '_with_harness', 'r') as file:
        total_code_with_harnesses = file.read


    reason, trace = cbmc_parsing.main(cbmc_output, total_code_with_harnesses, harness_method_list[0])
    #reiteration = cbmc_verification_status(file_name)
    return reason , trace
