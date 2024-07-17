import os

import json

import re

import subprocess

def extract_harnesses(code_str,method_list):
    total_harness_code = ""
    for function_method in method_list:
        start_marker = f"void proof_harness_{function_method}() {{"
        start_index = code_str.find(start_marker)

        if start_index == -1:
            return ""

        # Find the matching closing brace
        brace_count = 0
        for i in range(start_index, len(code_str)):
            if code_str[i] == '{':
                brace_count += 1
            elif code_str[i] == '}':
                brace_count -= 1
                if brace_count == 0:
                    end_index = i + 1
                    break

        proof_harness_method = code_str[start_index:end_index]
        total_harness_code = total_harness_code + proof_harness_method + '\n'

    return total_harness_code


def extract_variables(harness_only_c_code,method_name):
    pattern = rf'\b{method_name}\s*\(([^)]+)\)'
    matches = re.findall(pattern, harness_only_c_code)

    variables = []
    for match in matches:
        variables.extend([var.strip() for var in match.split(',')])

    return variables




def parse_cbmc_reason(json_text):
    try:
        data = json.loads(json_text)
        #print('done')
    except json.JSONDecodeError as e:
        return f"Invalid JSON: {e}"


    for entry in data:
        #this gives reason and location of syntax error

        if entry.get("messageType") == "ERROR":
            message_text = entry.get("messageText", "")
            if "syntax error" in message_text.lower():
                source_location = entry.get("sourceLocation", {})
                file = source_location.get("file", "unknown file")
                function = source_location.get("function", "unknown function")
                line = source_location.get("line", "unknown line")
                return {
                    "error_type": message_text,
                    "file": file,
                    "function": function,
                    "line": line
                }


        #this gives the reason for assertion failure

        if 'result' in entry:
            for result in entry['result']:
                if 'trace' in result:
                  last_item = result['trace'][-1]
                  return {
                      'error_type' : 'failed assertion',
                      'property' : last_item['property'] ,
                      'reason' : last_item['reason']
                  }

    # If no error found, return an empty string




    return "No error found"


#result = parse_cbmc_reason(json_text) #now test with trace example
#pretty_result = json.dumps(result, indent=4)

#print(pretty_result) # this holds the list of the reason and which assertion failed.


def extract_variable_values(data, variables):

    json_array_of_all_examples = []
    for entry in data:
        if 'result' in entry:
            for i in entry['result']:
                found_variables = {}
                example = {}
                #print(json.dumps(i, indent=2)) #really good for me to see assertions
                description = i['description']
                property_ = i['property']
                sourcelocation = i['sourceLocation']
                status = i['status']
                if status == 'FAILURE':
                    trace = i['trace']
                    for item in trace:
                        if item.get('assignmentType') == 'variable':
                            lhs = item.get('lhs')

                            if lhs in variables and lhs not in found_variables:  # finds the first call valued instance of the variable

                                found_variables[lhs] = item['value']

                example['property'] = property_
                example['description'] = description
                example['sourceLocation'] = sourcelocation
                example['status'] = status
                example['counter_example'] = found_variables
                json_array_of_all_examples.append(example)

    return json_array_of_all_examples

# Convert list to JSON string
#json_string = cbmc_result(cbmc_output_file))

# Replace double quotes with single quotes



#variables = input_names

#print(extract_variable_values(json_string, variables)) #for example: {'account': {'data': '((struct Account *)NULL)', 'name': 'pointer', 'type': 'struct Account *'}, 'amount': {'binary': '1111111111111111', 'data': '65535', 'name': 'integer', 'type': 'unsigned short int', 'width': 16}}

def parse_syntax_error(data):
    for entry in data:
        message = entry.get("messageText", "")

        if "syntax error" in message:
            return entry

    return None
def main(cbmc_output, total_code_with_harnesses, method_list):
    #assuming cbmc_output is a json string
    #total_code_with_harness also string
    #method also a string

    data = json.loads(cbmc_output) #converts string into json data

    for entry in data:
        message = entry.get("messageText", "")
        if "syntax error" in message:
            syntax = ['syntax']
            print('A syntax error was found on line ' + entry['sourceLocation']['line'])
            return syntax.append(entry['sourceLocation']['line'])
        if 'result' in entry:
            counter_examples = ['result']
            #cbmc_result = data #json data
            #print(cbmc_result)
            #print(total_code_with_harnesses)
            str_of_proof_harness = extract_harnesses(total_code_with_harnesses, method_list) #str of proof harnesses c code relevant to correct method
            #print(str_of_proof_harness)
            input_list = []
            for method in method_list:
                #print(method)
                var = extract_variables(str_of_proof_harness, method)
                #print(var)
                input_list = list(set(input_list + var)) #the input variables across all functions that we want to parse from the trace
            values_from_trace = (extract_variable_values(data, input_list))

            #print(values_from_trace)
            for example in values_from_trace:
                #print(json.dumps(example, indent = 2))
                if example["status"] == "SUCCESS":
                    #print()
                    print('On line ' + example['sourceLocation']['line'] + ', the test for \''+ example['description'] + '\' passed all tests successfully')

                elif example['status'] == 'FAILURE':
                    #print()
                    print('On line ' + example['sourceLocation']['line'] + ', the test for \'' + example[
                        'description'] + '\' failed under the following counter example: ')
                    for key, value in example['counter_example'].items():
                        print(key +' has input value ' + value['data'])
                        counter_examples.append([key,value['data']])
                    #print(list((example['counter_example']).keys())[0])

                    #print(json.dumps(example, indent = 2))
                    #print('no success')
            #print('the list of input variables is:')
            #print(input_list) #list of total variable names
             #these are the input variables found in a contradiction for the assertion
            #print('the counter examples and their values are:')
            #print(values_from_trace)
            return counter_examples


#main(cbmc_output, total_code_with_harnesses, method_list)  #returns the syntax msg or trae msg