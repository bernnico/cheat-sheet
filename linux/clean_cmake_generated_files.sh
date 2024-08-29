#!/bin/bash

# Find and remove common CMake-generated files and directories
declare -a cmake_files=(
    "CMakeCache.txt"
    "CMakeFiles"
    "cmake_install.cmake"
    "Makefile"
    "build.ninja"
    "*.ninja"
    "*.vcxproj"
    "*.vcxproj.filters"
    "*.sln"
    "*.xcodeproj"
)

# Iterate through the array and remove each file type
for file in "${cmake_files[@]}"; do
    find . -name "$file" -exec rm -rf {} +
done

echo "CMake-generated files have been cleaned up."
