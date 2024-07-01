import google.generativeai as genai
import os
import argparse
import Prompt_Generator as pg

#Generate a prompt
parser = argparse.ArgumentParser()
parser.add_argument("file_path", type=str)
args = parser.parse_args()

prompt = pg.main(args.file_path)


#Linking Gemini
genai.configure(api_key=os.environ['GENAI_API_KEY'])

model = genai.GenerativeModel('gemini-1.5-flash')

response = model.generate_content(prompt)
print(response.text)