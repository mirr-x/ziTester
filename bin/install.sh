#!/bin/bash

# Colors
GREEN='\033[32m'
RED='\033[31m'
YELLOW='\033[33m'
NC='\033[0m'
PURPLE='\033[35m'
Orange='\033[33m'
BLUE='\033[34m'

# Limited palette colors for terminals that don't support truecolor
FMT_LIM_RED="\033[38;5;196m"
FMT_LIM_ORANGE="\033[38;5;202m"
FMT_LIM_YELLOW="\033[38;5;226m"
FMT_LIM_GREEN="\033[38;5;082m"
FMT_LIM_BLUE="\033[38;5;021m"
FMT_LIM_PURPLE="\033[38;5;093m"
FMT_LIM_PINK="\033[38;5;163m"PURPLE
#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

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
echo "${FMT_LIM_YELLOW}Building the ziTester...${NC}\n\n"
if ! git clone https://github.com/mirr-x/ziTester "$TARGET_DIR"; then
    echo "${FMT_LIM_RED}Failed to clone the repository.${NC}"
    exit 1
fi

sleep 1

# Navigate to the directory containing the Makefile
cd "$TARGET_DIR/bin" || {
    echo "${FMT_LIM_RED}Failed to navigate to $TARGET_DIR/bin.${NC}"
    exit 1
}

# Check if Makefile exists and build the project
if [ -f "Makefile" ]; then
    if ! make; then
        echo "${FMT_LIM_RED}Build failed.${NC}"
        exit 1
    fi
else
    echo "${FMT_LIM_RED}No Makefile found in $TARGET_DIR. Skipping build step.${NC}"
    exit 1
fi

sleep 1

# Check if the binary exists
if [ ! -f "$EXE" ]; then
    echo "${FMT_LIM_RED}Executable not found: $EXE.${NC}"
    exit 1
fi

# Ensure the bin directory exists
if [ ! -d "$BIN_DIR" ]; then
    mkdir -p "$BIN_DIR"
fi

# Move the binary to the bin directory
if ! mv "$EXE" "$BIN_DIR"; then
    echo "${FMT_LIM_RED}Failed to move the binary to $BIN_DIR.${NC}"
    exit 1
fi

sleep 2

# Confirm completion
if [ -d "$TARGET_DIR" ]; then
    echo -e "${FMT_LIM_PURPLE}
     _ _____          _            
 ___(_)__   \___  ___| |_ ___ _ __ 
|_  / | / /\/ _ \/ __| __/ _ \ '__|
 / /| |/ / |  __/\__ \ ||  __/ |   
/___|_|\/   \___||___/\__\___|_|   
                                   
                                ${FMT_LIM_GREEN}....is now installed!${NC}"
    sleep 1
    echo -e "
${FMT_LIM_PURPLE}xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
                                                                          ${FMT_LIM_PURPLE}X
${FMT_LIM_RED}INSTRUCTIONS:${NC}                                                             ${FMT_LIM_PURPLE}X
                                                                          ${FMT_LIM_PURPLE}X
        ${FMT_LIM_ORANGE}• USAGE:${NC}                                                          ${FMT_LIM_PURPLE}X
            ${FMT_LIM_RED}$ >${NC} zi [FOLDER NAME]                                          ${FMT_LIM_PURPLE}X
                                                                          X
        ${FMT_LIM_ORANGE}• EXAMPLE:${NC}                                                        ${FMT_LIM_PURPLE}X
            ${FMT_LIM_RED}$ >${NC} zi C05                                                    ${FMT_LIM_PURPLE}X
                                                                          X
                                                                          X
${FMT_LIM_PURPLE}--------------------------------------------------------------------------%
Made By: mirr-x              &&     Made By: mdbentaleb                   |
https://github.com/mirr-x    &&     https://github.com/mdbentaleb         |
--------------------------------------------------------------------------%
${NC}
${NC}"

else
    echo -e "\n\n${FMT_LIM_RED}Failed to clone the repository.${NC}"
    exit 1
fi
