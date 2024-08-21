#!/bin/bash

# colors
GREEN='\033[32m'
RED='\033[31m'
YELLOW='\033[33m'
NC='\033[0m'
PURPLE='\033[35m'

# Define the path to the project and Makefile
TARGET_DIR="/home/$USER/ziTester"
MAKEFILE_PATH="$TARGET_DIR/bin/Makefile"

# Check if the directory exists
if [ -d "$TARGET_DIR" ]; then
    rm -rf "$TARGET_DIR"
fi

# Clone the repository
echo -e "${YELLOW}Building the Test Framework...${NC}"
git clone https://github.com/mirr-x/ziTester "$TARGET_DIR"

sleep 1

# Navigate to the directory containing the Makefile
cd "$TARGET_DIR/bin"

# Check if Makefile exists and build the project
if [ -f "Makefile" ]; then
    make
else
    echo -e "${RED}No Makefile found in $TARGET_DIR. Skipping build step.${NC}"
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
    echo -e "${GREEN}Test Framework successfully built and installed.${NC}"
else
    echo -e "${RED}Failed to clone the repository.${NC}"
fi
