#!/bin/bash

echo "Script Name: $0"
echo "Number of Arguments: $#"
echo "All Arguments (individually): $@"
echo "All Arguments (as a single word): $*"
echo "First Argument: $1"
echo "Second Argument: $2"

# Execute a command to check exit status
ls > /dev/null
echo "Exit Status of last command: $?"

# Print current shell PID
echo "Current Shell PID: $$"

# Run a background command to check last background PID
sleep 10 &
echo "PID of last background command: $!"

# Print current shell options
echo "Current Shell Options: $-"

# Use a command and then print the last argument
echo "Last Argument of the last command: $_"
