from llama_cpp import Llama
import argparse
import Prompt_Generator as pg

#Create a prompt
parser = argparse.ArgumentParser()
parser.add_argument("file_path", type=str)
args = parser.parse_args()

prompt = pg.main(args.file_path)

#Creating a LLM model
llm = Llama(
      model_path="/Users/hyoyeon/Desktop/UNI/Faculty Internship/Correctness-guided-Code-Generation-with-LLM/CorrectnessProof/codellama-7b-instruct.Q5_K_S.gguf",
      chat_format="llama-2",
      # n_gpu_layers=-1, # Uncomment to use GPU acceleration
      # seed=1337, # Uncomment to set a specific seed
      n_ctx=4096,
)

response = llm.create_chat_completion(
      stream=True,
      messages = [
          {"role": "system", "content": "Hello! What is 3+2?"},
          {
              "role": "user",
              "content":[
                  {"type": "text", "text": "What is 3+2?"}
              ]
          },
      ],
)

# response = response['choices'][0]['message']['content']
print(response)

# Iterate over the output and print it.
for chunk in response:
    delta = chunk['choices'][0]['delta']
    if 'role' in delta:
        print(delta['role'], end=': ', flush=True)
    elif 'content' in delta:
        print(delta['content'], end='', flush=True)