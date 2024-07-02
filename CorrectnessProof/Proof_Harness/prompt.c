[
  {
    "program": "CBMC 5.95.1 (cbmc-5.95.1)"
  },
  {
    "messageText": "**** WARNING: Use --unwinding-assertions to obtain sound verification results",
    "messageType": "WARNING"
  },
  {
    "messageText": "CBMC version 5.95.1 (cbmc-5.95.1) 64-bit x86_64 macos",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Parsing Proof_Harness/prompt_with_harness.c",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Converting",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Type-checking prompt_with_harness",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "function 'CPROVER_assume' is not declared",
    "messageType": "WARNING",
    "sourceLocation": {
      "file": "Proof_Harness/prompt_with_harness.c",
      "function": "proof_harness",
      "line": "27",
      "workingDirectory": "/Users/hyoyeon/Desktop/UNI/Faculty Internship/Correctness-guided-Code-Generation-with-LLM/CorrectnessProof"
    }
  },
  {
    "messageText": "function 'assert' is not declared",
    "messageType": "WARNING",
    "sourceLocation": {
      "file": "Proof_Harness/prompt_with_harness.c",
      "function": "proof_harness",
      "line": "37",
      "workingDirectory": "/Users/hyoyeon/Desktop/UNI/Faculty Internship/Correctness-guided-Code-Generation-with-LLM/CorrectnessProof"
    }
  },
  {
    "messageText": "Generating GOTO Program",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Adding CPROVER library (x86_64)",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Removal of function pointers and virtual functions",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Generic Property Instrumentation",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Running with 8 object bits, 56 offset bits (default)",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Starting Bounded Model Checking",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "**** WARNING: no body for function CPROVER_assume",
    "messageType": "WARNING"
  },
  {
    "messageText": "Runtime Symex: 0.00363867s",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "size of program expression: 149 steps",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "simple slicing removed 2 assignments",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Generated 2 VCC(s), 2 remaining after simplification",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Runtime Postprocess Equation: 2.6375e-05s",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Passing problem to propositional reduction",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "converting SSA",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Runtime Convert SSA: 0.00160012s",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Running propositional reduction",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Post-processing",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Runtime Post-process: 1.7e-05s",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Solving with MiniSAT 2.2.1 with simplifier",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "1683 variables, 925 clauses",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "SAT checker: instance is UNSATISFIABLE",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Runtime Solver: 0.00317375s",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "messageText": "Runtime decision procedure: 0.00483113s",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "result": [
      {
        "description": "max allocation size exceeded",
        "property": "malloc.assertion.1",
        "sourceLocation": {
          "file": "<builtin-library-malloc>",
          "function": "malloc",
          "line": "31",
          "workingDirectory": "/Users/hyoyeon/Desktop/UNI/Faculty Internship/Correctness-guided-Code-Generation-with-LLM/CorrectnessProof"
        },
        "status": "SUCCESS"
      },
      {
        "description": "max allocation may fail",
        "property": "malloc.assertion.2",
        "sourceLocation": {
          "file": "<builtin-library-malloc>",
          "function": "malloc",
          "line": "36",
          "workingDirectory": "/Users/hyoyeon/Desktop/UNI/Faculty Internship/Correctness-guided-Code-Generation-with-LLM/CorrectnessProof"
        },
        "status": "SUCCESS"
      },
      {
        "description": "assertion source->data == initial_source_data - amount",
        "property": "proof_harness.assertion.1",
        "sourceLocation": {
          "file": "Proof_Harness/prompt_with_harness.c",
          "function": "proof_harness",
          "line": "37",
          "workingDirectory": "/Users/hyoyeon/Desktop/UNI/Faculty Internship/Correctness-guided-Code-Generation-with-LLM/CorrectnessProof"
        },
        "status": "SUCCESS"
      },
      {
        "description": "assertion dest->data == initial_dest_data + amount",
        "property": "proof_harness.assertion.2",
        "sourceLocation": {
          "file": "Proof_Harness/prompt_with_harness.c",
          "function": "proof_harness",
          "line": "38",
          "workingDirectory": "/Users/hyoyeon/Desktop/UNI/Faculty Internship/Correctness-guided-Code-Generation-with-LLM/CorrectnessProof"
        },
        "status": "SUCCESS"
      }
    ]
  },
  {
    "messageText": "VERIFICATION SUCCESSFUL",
    "messageType": "STATUS-MESSAGE"
  },
  {
    "cProverStatus": "success"
  }
]
