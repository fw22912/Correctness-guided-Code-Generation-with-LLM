#!/bin/bash

# Loop through all .c files in the C_Examples directory
for file in C_Examples/*.c
do
    # Execute the Python script with the current file as an argument
    python3 main.py "$file"
done

