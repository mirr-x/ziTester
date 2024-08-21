#!/bin/sh

# Define color variables
FMT_RED="\033[31m"
FMT_GREEN="\033[32m"
FMT_YELLOW="\033[33m"
FMT_BLUE="\033[34m"
FMT_BOLD="\033[1m"
FMT_RESET="\033[0m"

# Truecolor colors for rainbow effect
FMT_RAINBOW_RED="\033[38;2;255;0;0m"
FMT_RAINBOW_ORANGE="\033[38;2;255;97;0m"
FMT_RAINBOW_YELLOW="\033[38;2;247;255;0m"
FMT_RAINBOW_GREEN="\033[38;2;0;255;30m"
FMT_RAINBOW_BLUE="\033[38;2;77;0;255m"
FMT_RAINBOW_PURPLE="\033[38;2;168;0;255m"
FMT_RAINBOW_PINK="\033[38;2;245;0;172m"

# Limited palette colors for terminals that don't support truecolor
FMT_LIM_RED="\033[38;5;196m"
FMT_LIM_ORANGE="\033[38;5;202m"
FMT_LIM_YELLOW="\033[38;5;226m"
FMT_LIM_GREEN="\033[38;5;082m"
FMT_LIM_BLUE="\033[38;5;021m"
FMT_LIM_PURPLE="\033[38;5;093m"
FMT_LIM_PINK="\033[38;5;163m"

# Example usage of colors
echo -e "${FMT_RED}This is red text${FMT_RESET}"
echo -e "${FMT_GREEN}This is green text${FMT_RESET}"
echo -e "${FMT_YELLOW}This is yellow text${FMT_RESET}"
echo -e "${FMT_BLUE}This is blue text${FMT_RESET}"
echo -e "${FMT_BOLD}This is bold text${FMT_RESET}"

echo -e "${FMT_RAINBOW_RED}This is rainbow red text${FMT_RESET}"
echo -e "${FMT_RAINBOW_ORANGE}This is rainbow orange text${FMT_RESET}"
echo -e "${FMT_RAINBOW_YELLOW}This is rainbow yellow text${FMT_RESET}"
echo -e "${FMT_RAINBOW_GREEN}This is rainbow green text${FMT_RESET}"
echo -e "${FMT_RAINBOW_BLUE}This is rainbow blue text${FMT_RESET}"
echo -e "${FMT_RAINBOW_PURPLE}This is rainbow purple text${FMT_RESET}"
echo -e "${FMT_RAINBOW_PINK}This is rainbow pink text${FMT_RESET}"

echo -e "${FMT_LIM_RED}This is limited palette red text${FMT_RESET}"
echo -e "${FMT_LIM_ORANGE}This is limited palette orange text${FMT_RESET}"
echo -e "${FMT_LIM_YELLOW}This is limited palette yellow text${FMT_RESET}"
echo -e "${FMT_LIM_GREEN}This is limited palette green text${FMT_RESET}"
echo -e "${FMT_LIM_BLUE}This is limited palette blue text${FMT_RESET}"
echo -e "${FMT_LIM_PURPLE}This is limited palette purple text${FMT_RESET}"
echo -e "${FMT_LIM_PINK}This is limited palette pink text${FMT_RESET}"
