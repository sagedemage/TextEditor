#!/bin/bash

# Create the build directory if it does not exist
if [[ ! -d "build" ]]
then
    mkdir build
fi

# Go to the build directory
cd build

# Remove main executable if it exists
if [[ -f "main" ]]
then
    rm main
fi

# Compile the program
cmake --build .

# Run the main program if it compiles successfully
if [[ -f "main" ]]
then
    ./main
fi
