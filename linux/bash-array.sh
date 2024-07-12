#!/bin/bash

# Create an array with some elements
args=("argument one" "argument two" "argument three")

# Standard expressions for the index operator
echo "Standard expressions:"
echo "First argument: ${args[0]}"
echo "Second argument: ${args[1]}"
echo "Third argument: ${args[2]}"
echo

# Special expressions for the index operator

# All elements of the array as separate words using @
echo "All elements (using @): ${args[@]}"
echo

# All elements of the array as a single word using *
echo "All elements (using *): ${args[*]}"
echo

# Indices of the array using @
echo "Indices (using @): ${!args[@]}"
echo

# Number of elements in the array using @
echo "Number of elements (using @): ${#args[@]}"
echo

# Iteration over all elements with @ and indices
echo "Iteration over all elements with @ and indices:"
for index in "${!args[@]}"
do
    echo "Index: $index, Element: ${args[$index]}"
done
echo
