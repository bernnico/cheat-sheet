#!/bin/bash

# Additional supported comparison operators:
# - Numerical comparisons: -lt (less than), -le (less than or equal), -gt (greater than), -ge (greater than or equal)
# - String comparisons: = (equal), != (not equal), -z (empty), -n (not empty)
# - File tests: -f (is a regular file), -d (is a directory), -e (exists)

# Numerical comparison
number=10

if [ $number -eq 10 ]; then
    echo "Numerical comparison: The number is equal to 10."
fi

# String comparison
string1="hello"
string2="world"

if [ "$string1" = "$string2" ]; then
    echo "String comparison: The strings are equal."
else
    echo "String comparison: The strings are not equal."
fi

# Check for file existence
file="my-file.txt"

if [ -f "$file" ]; then
    echo "File existence check: The file $file exists and is a regular file."
fi

# Logical expression (AND condition)
number1=5
number2=10

if [ $number1 -lt 10 ] && [ $number2 -gt 5 ]; then
    echo "Logical expression: Both conditions are true."
fi

# Negating the logical expression
if ! [ $number1 -lt 10 ] || ! [ $number2 -gt 5 ]; then
    echo "Negated logical expression: At least one of the conditions is false."
fi

# Example for -lt (less than) and -n (not empty)
number3=3
string3=""

if [ $number3 -lt 5 ] && [ -n "$string3" ]; then
    echo "Additional conditions: The number is less than 5 and the string is not empty."
fi
