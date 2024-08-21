#!/bin/bash

# Define the path to the project and Makefile
TARGET_DIR="/home/$USER/ziTester"
MAKEFILE_PATH="$TARGET_DIR/bin/Makefile"
bin_PATH="$TARGET_DIR/bin/ziTester"

# Check if the directory exists
if [ -d "$TARGET_DIR" ]; then
    echo "Directory $TARGET_DIR exists. Deleting it..."
    rm -rf "$TARGET_DIR"
    echo "Directory deleted."
fi

# Clone the repository
echo "Cloning the repository..."
git clone https://github.com/mirr-x/ziTester "$TARGET_DIR"

# Navigate to the directory containing the Makefile
cd "$TARGET_DIR/bin"

# Check if Makefile exists and build the project
if [ -f "Makefile" ]; then
    echo "Building the project using Makefile..."
    make
    echo "Build completed."
else
    echo "No Makefile found in $TARGET_DIR. Skipping build step."
fi

EXE="$TARGET_DIR/bin/ziTester"
BIN_DIR="/home/$USER/.local/bin"

# Check if the binary exists

if [ ! -d "$BIN_DIR" ]; then
    echo "$BIN_DIR does not exist. Creating directory..."
    mkdir -p "$BIN_DIR"
    echo "$BIN_DIR created."
fi

# Move the binary to the bin directory
echo "Moving the binary to $BIN_DIR..."
mv "$EXE" "$BIN_DIR"
echo "Binary moved."

# Check if norminette is installed
if ! command -v norminette &> /dev/null; then
    echo "norminette not found. Installing norminette..."
    python3 -m pip install --upgrade pip setuptools
    python3 -m pip install norminette
    echo "norminette installed."
else
    echo "norminette is already installed."
fi

# Confirm completion
if [ -d "$TARGET_DIR" ]; then
    echo "Repository successfully cloned and built at $TARGET_DIR."
else
    echo "Failed to clone the repository."
fi

