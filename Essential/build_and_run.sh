#!/bin/bash

# Navigate to the source directory
cd "$(dirname "$0")"

# Compile
echo "Compiling..."
clang++ -std=c++17 -o main main.cpp array_ADT/ArrayADT.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "✓ Compilation successful!"
    echo ""
    echo "Running program..."
    echo "---"
    ./main
else
    echo "✗ Compilation failed!"
    exit 1
fi

