"""
Install the Google AI Python SDK

$ pip install google-generativeai

See the getting started guide for more information:
https://ai.google.dev/gemini-api/docs/get-started/python
"""

import os
import pathlib
import textwrap


import google.generativeai as genai
# from google.colab import userdata

genai.configure(api_key="AIzaSyB5dDr6a-rnJWEBu5Rky_nMdcMBWtVUy7k")

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
  # safety_settings = Adjust safety settings
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

response = chat_session.send_message("How are you today?")

print(response.text)