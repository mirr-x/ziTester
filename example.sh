#!/bin/bash

# Print a message
echo "Running example.sh..."

# Simulate some work with a variable
value=10

# Check a condition and set the exit status
if [ "$value" -eq 10 ]; then
    echo "Success: value is 10"
    exit 9  # Exit with status 0 (success)
else
    echo "Failure: value is not 10"
    exit 1  # Exit with status 1 (failure)
fi
