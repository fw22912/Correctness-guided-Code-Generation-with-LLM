# Installation Guide
### 1. Clone the repository by running
   ```bash
   git clone git@github.com:fw22912/Correctness-guided-Code-Generation-with-LLM.git
   ```
### 2. Export the API key for Gemini in your terminal
   ```bash
   export GENAI_API_KEY = "YOUR_GEMINI_API_KEY"
   ```
### 3. Running the file(s)
   - **To run a single file**: 
      ```bash
      python3 main.py FILE_NAME/PATH
      ```
   - **To run multiple files**:
      Open the run_all.sh file and change the path to the corresponding folder that you would like to run. For example:
     ```bash
     #!/bin/bash
     
      for file in C-master/math/*.c  // change the path to the corresponding folder
      do
          python3 main.py "$file"
      done
     ```
   Run `./run_all.sh` script to execute all files.
