import json
import subprocess
import os
import Gemini as gemini
import argparse
import CounterExample_Generator as cg
import cbmc_parsing
import tempfile
import signal
import sys

# Handler function to raise a timeout exception
def handler(signum, frame):
    raise TimeoutError("The program took too long to complete")




def run_cbmc(file_path, total_code_with_harnesses, harness_method_list): ## this bit is needed in case the json file is too large to store in a string?
    import os
    import subprocess

    output_path = 'CBMC_Result'
    original_file_name = os.path.splitext(os.path.basename(file_path))[0]
    harness_file_name = original_file_name + "_with_harness"
    cbmc_output_file = os.path.join(output_path, original_file_name + "_cbmc.json")

    harness_command = " ".join([f"--function {method}" for method in harness_method_list])

    with tempfile.NamedTemporaryFile( suffix=".c", delete=False) as temp_file:
        temp_file.write(total_code_with_harnesses.encode('utf-8'))
        temp_file_path = temp_file.name

    command_str = f'cbmc {temp_file_path} --function combined_proof_harness --no-standard-checks --no-malloc-may-fail --verbosity 8 --unwind 3 --trace --json-ui'
    print(f'cbmc {harness_file_name}.c --function combined_proof_harness --no-standard-checks --no-malloc-may-fail --verbosity 8 --unwind 3 --trace --json-ui')

    #print(total_code_with_harnesses)

    # Set the signal handler and a timeout alarm
    signal.signal(signal.SIGALRM, handler)
    signal.alarm(20)  # Timeout after 20 seconds

    try:
        result = subprocess.run(command_str,
        shell=True, capture_output=True, text=True)
        #print(result)
        cbmc_json_string = result.stdout

        return cbmc_json_string
    except TimeoutError as e:
        print('cbmc took too long to run')



    except Exception as e:
        print(f"An unexpected error occurred, likely because the json file storing the output was too big for the string. This program will proceed now by storing it in a file : {e}")
        with open(cbmc_output_file, 'w+') as file:
            subprocess.run(command_str, shell=True, stdout=file)
        #print('cbmc output file:', cbmc_output_file)
        return cbmc_output_file

    finally:
        os.remove(temp_file_path)
        # Disable the alarm
        signal.alarm(0)


def cbmc_string_or_file(query_string): #leave for later, assume string for now
    if "_cbmc.json" in query_string:
        return 'file'
    else:
        return 'string'

def cbmc_verification_status(json_str):
    data = json.loads(json_str)
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

    cbmc_output = run_cbmc(file_path, total_code_with_harnesses, harness_method_list) ###############under the current assumption that the json string isn't too big

    reiteration = cbmc_verification_status(cbmc_output)


    method_list = [item.replace('proof_harness_', '') for item in harness_method_list]
    #print(method_list)

    parse = cbmc_parsing.main(cbmc_output, total_code_with_harnesses, method_list)


    return reiteration, parse
