import argparse
import Gemini
import cbmc_call
import os
import Prompt_Generator as prompt_generator
import CounterExample_Generator as counter_example_generator
import time
import tracemalloc
import pandas as pd
import re
import openpyxl
from openpyxl import Workbook
from datetime import datetime
import os
import time

def extract_harness_name(file_content):
    function_pattern = re.compile(r'\b[a-zA-Z_]\w*\s+\*?\b(proof_harness\w*)\s*\([^)]*\)\s*\{')
    matches = function_pattern.findall(file_content)

    method_names = [match for match in matches if match not in {"main", "if", "for", "while"}]

    return method_names


def generate_proof_harness(method_list):
    return ["proof_harness_" + method for method in method_list]


def run_benchmark(file_path):
    results = []
    file_name = os.path.splitext(os.path.basename(file_path))[0]
    print("\nFile name: " + file_name + ".c")
    prompt, method_list, file_content = prompt_generator.main(file_path)
    harness_list = generate_proof_harness(method_list)

    start_time = time.time()
    tracemalloc.start()
    success = False
    iterations = 0
    cnt = 0

    while True:
        try:
            response_text = Gemini.main(prompt, file_path, method_list)
            reiteration = cbmc_call.main(file_path, harness_list)
            iterations += 1

            if reiteration == True:
                print("Verification successful")
                success = True
                break
            elif cnt > 1:
                print("Verification failed. Moving on to the next example...\n")
                break
            else:
                print("Verification Failed. Retrying with a new prompt with counterexamples...")
                # counter_examples = None
                # prompt = counter_example_generator.create_prompt(file_content, response_text, counterexamples=counter_examples)
                # print(f"New Prompt Generated:\n{prompt}")
                cnt += 1

        except Exception as e:
            print(f"An unexpected error occurred: {e}")
            break

    end_time = time.time()
    memory_used = tracemalloc.get_traced_memory()[1]
    tracemalloc.stop()

    results.append({
        'file_name': file_name,
        'success': success,
        'iterations': iterations,
        'execution_time': end_time - start_time,
        'memory_used': memory_used
    })

    return results


def main(file_paths):
    all_results = []
    for file_path in file_paths:
        results = run_benchmark(file_path)
        all_results.extend(results)

    df = pd.DataFrame(all_results)
    df.to_csv('benchmark_results.csv', index=False)
    print(df)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("file_paths", type=str, nargs='+', help="Paths to the files to benchmark")
    args = parser.parse_args()
    main(args.file_paths)
