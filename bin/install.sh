#!/bin/bash

# Define the path to the project and Makefile
TARGET_DIR="/home/$USER/ziTester"
MAKEFILE_PATH="$TARGET_DIR/bin/Makefile"

# Check if the directory exists
if [ -d "$TARGET_DIR" ]; then
    rm -rf "$TARGET_DIR"
fi

# Clone the repository
echo -e "Building the Test Framework...\n"
git clone https://github.com/mirr-x/ziTester "$TARGET_DIR"

sleep 1


# Navigate to the directory containing the Makefile
cd "$TARGET_DIR/bin"

# Check if Makefile exists and build the project
if [ -f "Makefile" ]; then
    make
else
    echo "No Makefile found in $TARGET_DIR. Skipping build step."
fi

sleep 1

EXE="$TARGET_DIR/bin/zi"
BIN_DIR="/home/$USER/.local/bin"

# Check if the binary exists

if [ ! -d "$BIN_DIR" ]; then
    mkdir -p "$BIN_DIR"
fi

# Move the binary to the bin directory
mv "$EXE" "$BIN_DIR"

sleep 1

# Confirm completion
if [ -d "$TARGET_DIR" ]; then
    echo -e "Test Framework successfully built and installed.\n"
else
    echo "Failed to clone the repository."
fi

