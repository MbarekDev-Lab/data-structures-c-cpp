#!/bin/bash

# Navigate to the project root directory
cd "$(dirname "$0")"

# Compile (using ArrayMenu.c for arraysMenu() function)
echo "Compiling..."

# 1. Compile C component (force C language for .cpp file)
clang -c -x c "ArrayDSA/ArrayMenuusing_C /ArrayMenu.cpp" -o ArrayMenu.o
if [ $? -ne 0 ]; then
    echo "✗ C Compilation failed!"
    exit 1
fi

# 2. Compile C++ component and link
clang++ -std=c++17 -o main Essential.cpp ArrayDSA/array_ADT/ArrayADT.cpp ArrayMenu.o

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "✓ Compilation successful!"
    echo ""
    echo "Running program..."
    echo "---"
    rm ArrayMenu.o
    ./main
else
    echo "✗ Compilation failed!"
    rm -f ArrayMenu.o
    exit 1
fi
