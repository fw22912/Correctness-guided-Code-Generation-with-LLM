"""
Install the Google AI Python SDK

$ pip install google-generativeai

See the getting started guide for more information:
https://ai.google.dev/gemini-api/docs/get-started/python
"""
import argparse
import os
import pathlib
import textwrap


import google.generativeai as genai
import Prompt_Generator as pg

# from google.colab import userdata

genai.configure(api_key="AIzaSyB5dDr6a-rnJWEBu5Rky_nMdcMBWtVUy7k")

parser = argparse.ArgumentParser()
parser.add_argument("file_path", type=str)
args = parser.parse_args()

prompt = pg.main(args.file_path)


# Create the model
# See https://ai.google.dev/api/python/google/generativeai/GenerativeModel
generation_config = {
  "temperature": 1,
  "top_p": 0.95,
  "top_k": 64,
  "max_output_tokens": 8192,
  "response_mime_type": "text/plain",
}

model = genai.GenerativeModel(
  model_name="gemini-1.5-pro",
  generation_config=generation_config,
  # See https://ai.google.dev/gemini-api/docs/safety-settings
)


chat_session = model.start_chat(
  history=[
    {
      "role": "user",
      "parts": [
        "Hello, introduce yourself",
      ],
    },
  ]
)

response = chat_session.send_message(prompt)

print(response.text)