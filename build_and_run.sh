#!/bin/bash

# Navigate to the project root directory
cd "$(dirname "$0")"

# Compile (using ArrayMenu.c for arraysMenu() function)
echo "Compiling..."

# 1. Compile C component (ArrayMenu.c contains all the array functions)
clang -c "ArrayDSA/ArrayMenuusing_C /ArrayMenu.c" -o ArrayMenu.o
if [ $? -ne 0 ]; then
    echo "✗ ArrayMenu.c compilation failed!"
    exit 1
fi

# 2. Compile C++ component and link with C object file
clang++ -std=c++17 -o main Essential.cpp ArrayMenu.o

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "✓ Compilation successful!"
    echo ""
    echo "Running program..."
    echo "---"
    rm -f ArrayMenu.o
    ./main
else
    echo "✗ Compilation failed!"
    rm -f ArrayMenu.o
    exit 1
fi
