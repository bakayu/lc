#!/bin/bash

# Check if filename is provided
if [ $# -eq 0 ]; then
    echo "Usage: ./run.sh <filename.cpp>"
    echo "Example: ./run.sh hello.cpp"
    exit 1
fi

# Get the filename and extract name without extension
filename=$1
basename=$(basename "$filename" .cpp)

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "Error: File '$filename' not found!"
    exit 1
fi

echo "Compiling $filename..."

# Compile the C++ file
clang++ -o "$basename" "$filename"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo "Running $basename..."
    echo "===================="
    echo ""
    ./"$basename"
    echo ""
    echo "===================="
    echo "Execution completed."
    
    # Optional: Remove the executable after running
    rm "$basename"
else
    echo "Compilation failed!"
    exit 1
fi