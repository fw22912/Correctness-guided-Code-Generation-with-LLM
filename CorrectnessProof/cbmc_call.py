import subprocess
import os
import Gemini as gemini
import argparse
import CounterExample_Generator as cg

def run_cbmc(file_path):
    # file = open(file_path, 'w+')
    output_path = 'CBMC_Result'
    original_file_name = os.path.splitext(os.path.basename(file_path))[0]
    harness_file_name = original_file_name + "_with_harness.c"
    print("HarnessFILE name: " + harness_file_name)
    cbmc_output_file = os.path.join(output_path, original_file_name + "_cbmc.json")

    with open(cbmc_output_file, 'w+') as file:
        subprocess.run(f'cbmc Proof_Harness/{harness_file_name} --function proof_harness --unwind 5 --trace --json-ui', shell=True, stdout=file)

    return cbmc_output_file

def cbmc_result_parsing(file_name):
    cbmc_result_file = "CBMC_Result" + file_name + "_cbmc.json"
    cbmc_pass = True
    return cbmc_pass


def create_couter_example_prompt(original_code, prev_output, counter_examples):
    counter_prompt = cg.main(original_code, prev_output, counter_examples)
    return counter_prompt

def main(file_path):
    file_name = os.path.splitext(os.path.basename(file_path))[0]
    # gemini.main(file_path)
    print("Running CBMC...")
    run_cbmc(file_path)
    reiteration = cbmc_result_parsing(file_name)
    return reiteration
