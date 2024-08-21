#!/bin/bash

# Colors
GREEN='\033[32m'
RED='\033[31m'
YELLOW='\033[33m'
NC='\033[0m'
PURPLE='\033[35m'

# Define the path to the project and Makefile
TARGET_DIR="/home/$USER/ziTester"
MAKEFILE_PATH="$TARGET_DIR/bin/Makefile"
EXE="$TARGET_DIR/bin/zi"
BIN_DIR="/home/$USER/.local/bin"

# Check if the directory exists and remove it
if [ -d "$TARGET_DIR" ]; then
    rm -rf "$TARGET_DIR"
fi

# Clone the repository
echo "${YELLOW}Building the ziTester...${NC}\n\n"
if ! git clone https://github.com/mirr-x/ziTester "$TARGET_DIR"; then
    echo "${RED}Failed to clone the repository.${NC}"
    exit 1
fi

sleep 1

# Navigate to the directory containing the Makefile
cd "$TARGET_DIR/bin" || { echo "${RED}Failed to navigate to $TARGET_DIR/bin.${NC}"; exit 1; }

# Check if Makefile exists and build the project
if [ -f "Makefile" ]; then
    if ! make; then
        echo "${RED}Build failed.${NC}"
        exit 1
    fi
else
    echo "${RED}No Makefile found in $TARGET_DIR. Skipping build step.${NC}"
    exit 1
fi

sleep 1

# Check if the binary exists
if [ ! -f "$EXE" ]; then
    echo "${RED}Executable not found: $EXE.${NC}"
    exit 1
fi

# Ensure the bin directory exists
if [ ! -d "$BIN_DIR" ]; then
    mkdir -p "$BIN_DIR"
fi

# Move the binary to the bin directory
if ! mv "$EXE" "$BIN_DIR"; then
    echo "${RED}Failed to move the binary to $BIN_DIR.${NC}"
    exit 1
fi

sleep 1

# Confirm completion
if [ -d "$TARGET_DIR" ]; then
    echo -e "${PURPLE}

           /$$ /$$$$$$$$                    /$$                        
          |__/|__  $$__/                   | $$                        
 /$$$$$$$$ /$$   | $$  /$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$ 
|____ /$$/| $$   | $$ /$$__  $$ /$$_____/|_  $$_/   /$$__  $$ /$$__  $$
   /$$$$/ | $$   | $$| $$$$$$$$|  $$$$$$   | $$    | $$$$$$$$| $$  \__/
  /$$__/  | $$   | $$| $$_____/ \____  $$  | $$ /$$| $$_____/| $$      
 /$$$$$$$$| $$   | $$|  $$$$$$$ /$$$$$$$/  |  $$$$/|  $$$$$$$| $$      
|________/|__/   |__/ \_______/|_______/    \___/   \_______/|__/      
                                                                       
                                                            
                                                            
${NC}"

    echo -e "\n\n\t\t\t\t\t\t\t\t\t${GREEN}....is now installed!${NC}"
else
    echo -e "\n\n${RED}Failed to clone the repository.${NC}"
    exit 1
fi
