import transformers
from transformers import AutoTokenizer
import torch
import Prompt_Generator as pg
import argparse

#Create a parser and generate a prompt
parser = argparse.ArgumentParser()
parser.add_argument("file_path", type = str)
args = parser.parse_args()
prompt = pg.main(args.file_path)
print("Prompt: " + prompt)

#Load the model
model = "meta-llama/CodeLlama-7b-hf"
tokenizer = AutoTokenizer.from_pretrained(model)
pipeline = transformers.pipeline("text-generation",
                                 model=model,
                                 torch_dtype=torch.float16,
                                 device_map="auto")

sequences = pipeline(
    f"{prompt}",
    do_sample=True,
    top_k=10,
    temperature=0.1,
    top_p=0.95,
    num_return_sequences=1,
    eos_token_id=tokenizer.eos_token_id,
    max_length= 1024,
)

for seq in sequences:
    print(f"Result: {seq['generated_text']}")


# genai.configure(api_key="AIzaSyB5dDr6a-rnJWEBu5Rky_nMdcMBWtVUy7k")
#
# parser = argparse.ArgumentParser()
# parser.add_argument("file_path", type=str)
# args = parser.parse_args()
#
# prompt = pg.main(args.file_   path)
#
#
# # Create the model
# # See https://ai.google.dev/api/python/google/generativeai/GenerativeModel
# generation_config = {
#   "temperature": 1,
#   "top_p": 0.95,
#   "top_k": 64,
#   "max_output_tokens": 8192,
#   "response_mime_type": "text/plain",
# }
#
# model = genai.GenerativeModel(
#   model_name="gemini-1.5-pro",
#   generation_config=generation_config,
#   # See https://ai.google.dev/gemini-api/docs/safety-settings
# )
#
#
# chat_session = model.start_chat(
#   history=[
#     {
#       "role": "user",
#       "parts": [
#         "Hello, introduce yourself",
#       ],
#     },
#   ]
# )
#
# response = chat_session.send_message(prompt)
#
# print(response.text)
