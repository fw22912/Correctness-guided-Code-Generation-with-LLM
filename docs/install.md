# Installation Guide
1. Clone the repository by running
   ```bash
   git clone git@github.com:fw22912/Correctness-guided-Code-Generation-with-LLM.git
   ```
2. Export the API key for Gemini in your terminal
   ```bash
   export GENAI_API_KEY = "YOUR_GEMINI_API_KEY"
   ```
3. Running the file(s)
   The current implementation cannot run multiple files in an identical way running a single file. 
   - To run a **single file**: 
      ```bash
      python3 main.py FILE_NAME/PATH
      ```
   - **To run multiple files**:
     Change the path in ```run_all.sh``` to the corresponding file path that you would like to run.
     ```bash
     #!/bin/bash
     
      for file in C-master/math/*.c  // change the path to the corresponding folder
      do
          python3 main.py "$file"
      done
     ```
     Run `./run_all.sh` to execute.
