#!/bin/bash

# Colors
YELLOW='\033[33m'
RED='\033[31m'
GREEN='\033[32m'
NC='\033[0m'

# Clone the repository
echo -e "${YELLOW}Building the Test Framework...${NC}\n"
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
    echo -e "${GREEN}Test Framework successfully built and installed.${NC}\n"
else
    echo -e "${RED}Failed to clone the repository.${NC}"
fi