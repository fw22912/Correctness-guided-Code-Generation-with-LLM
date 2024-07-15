import os

import json

import re

import subprocess

method = 'withdraw'

total_code_with_harnesses = '''
struct Account {
    unsigned short bal;
};

// Function to withdraw an amount from an account
void withdraw(struct Account *account, unsigned short amount) {
    unsigned short de = account->bal;
    account->bal = de - amount;
}

void proof_harness_withdraw() {
    struct Account *account;
    int amount;
    __CPROVER_assume(account->bal >= 0);
    __CPROVER_assume(amount > 0)
    __CPROVER_assume(account->bal >= amount);

    // Save the initial balance for verification
    unsigned short initial_balance = account->bal;

    withdraw(account, amount);

    // Check that the new balance is the expected value after withdrawal
    assert(account->bal == initial_balance - amount);
}
'''
# cbmc output for withdraw
cbmc_output = '''
[
  {
    "program": "CBMC 6.0.1 (cbmc-6.0.1)"
  },
  {
    "messageText": "**** WARNING: Use --unwinding-assertions to obtain sound verification results",
    "messageType": "WARNING"
  },
  {
    "messageText": "CBMC version 6.0.1 (cbmc-6.0.1) 64-bit x86_64 macos",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "syntax error before '__CPROVER_assume'",
    "messageType": "ERROR",
    "sourceLocation": {
      "file": "withdraw.c",
      "function": "proof_harness_withdraw",
      "line": "18",
      "workingDirectory": "/Users/osc/Desktop/test_c"
    }
  },
  {
    "messageText": "PARSING ERROR",
    "messageType": "ERROR"
  }
]
'''


def find_input_names(proof_harness, function_name): #C_code and function_name are both expected as strings
    # Create the regular expression pattern using the function name
    pattern = fr'{function_name}\(([^)]+)\)'

    # Search for the pattern in the proof harness
    match = re.search(pattern, proof_harness)

    if match:
        # Extract the inputs and split by comma
        inputs = match.group(1).split(',')
        # Strip any extra whitespace from each input
        inputs = [input_name.strip() for input_name in inputs]
        return inputs
    else:
        return []



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


def extract_variable_values(cbmc_result, variables):
    data = json.loads(cbmc_result)
    found_variables = {}
    #print(data['trace'])

    def find_variables(trace):
        for item in trace:
            if item.get('assignmentType') == 'variable':
                variable_name = item.get('lhs')
                if variable_name in variables and variable_name not in found_variables:
                    found_variables[variable_name] = item.get('value')


    find_variables(data['trace'])


    return found_variables

# Convert list to JSON string
#json_string = cbmc_result(cbmc_output_file))

# Replace double quotes with single quotes



#variables = input_names

#print(extract_variable_values(json_string, variables)) #for example: {'account': {'data': '((struct Account *)NULL)', 'name': 'pointer', 'type': 'struct Account *'}, 'amount': {'binary': '1111111111111111', 'data': '65535', 'name': 'integer', 'type': 'unsigned short int', 'width': 16}}

def extract_proof_harness(code_str,function_method):
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
    return proof_harness_method

def main(cbmc_output, total_code_with_harnesses, method):
    #assuming cbmc_output is a json string
    #total_code_with_harness also string
    #method also a string
    print('The type of error is:')
    cbmc_reason = (parse_cbmc_reason(cbmc_output))
    print(cbmc_reason)
    if cbmc_reason == "No error found":
        return {'No error found'}, None
    else:
        data = json.loads(cbmc_output) #converts string into json data
        for entry in data:
            if 'result' in entry:
                cbmc_result = json.dumps(entry['result'][0], indent= 2) #json data of only result
                #print(cbmc_result)
                str_of_proof_harness = extract_proof_harness(total_code_with_harnesses,method) #str of proof harness c code relevant to correct method
                #print(str_of_proof_harness)
                input_list = find_input_names(str_of_proof_harness,method) #the input variables we want to parse from the trace
                #print(input_list)
                values_from_trace = extract_variable_values(cbmc_result,input_list) #these are the input variables found in a contradiction for the assertion
                print('the counter examples and their values are:')
                print(values_from_trace)
                return cbmc_reason, values_from_trace

        return cbmc_reason, None

#main(cbmc_output, total_code_with_harnesses, method)