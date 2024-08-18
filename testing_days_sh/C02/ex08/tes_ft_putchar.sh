#!/bin/bash

path_main=/home/$USER/ziTester/main-files_days/C02/ex08/main.c
path_exe=/home/$USER/ziTester/main-files_days/C02/ex08/user_exe
path_file=ex08/ft_putchar.c
path_expected_output=/home/$USER/ziTester/main-files_days/C02/ex08/expected_output
path_user_output=/home/$USER/ziTester/main-files_days/C02/ex08/user_output
path_diff_output=/home/$USER/ziTester/main-files_days/C02/ex08/diff_output
path_norm_output=/home/$USER/ziTester/main-files_days/C02/ex08/norm_output

# colors
GREEN='\033[32m'
RED='\033[31m'
YELLOW='\033[33m'
RESET='\033[0m'
PURPLE='\033[35m'

#check normin
norminette $path_file > $path_norm_output

# Check if ": OK!" is present in the norminette output file
if grep -q ": OK!" "$path_norm_output"; then
    echo -e "${GREEN} -> NORMINETTE OK ${RESET}"
else
    echo -e "${RED}\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX${RESET}"
    echo -e "${RED}\n\t\t !! HERE IS THE NORM OUTPUT !! \n${RESET}"
    cat "$path_norm_output"
    echo -e "${RED}\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX${RESET}"
fi

# run the code and compile it with the main file
gcc -Wall -Wextra -Werror $path_main $path_file -o $path_exe

# test the code and get the output in a file
$path_exe > $path_user_output

# compare the user_output and expcted_output

diff $path_user_output $path_expected_output > $path_diff_output

# check if the diff_output is empty
size_diff_output=$(stat -c%s $path_diff_output)
status=0

if [ $size_diff_output -eq 0 ]
then
    status=1
    echo -e "${GREEN} -> $path_file OK ${RESET}"
else
    status=-1
    echo -e "${RED}\n -> $path_file KO ${RESET}"
    echo -e "${RED}\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX${RESET}"
    echo -e "${RED}\n\t\t !! HERE IS THE DIFF OUTPUT !! ${RESET}"
    echo -e "${PURPLE}\n\t\t\t > YOUR_OUTPUT${RESET}"
    cat $path_user_output
    echo -e "${PURPLE}\n\t\t\t < EXPECTED_OUTPUT${RESET}"
    cat $path_expected_output
    echo -e "${RED}\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX${RESET}"
fi

if [ $status -eq 1 ]
then
    echo -e "${YELLOW}\n******************************************************************************************${RESET} ${GREEN}  OK  { ✔️  } ${RESET}"
else
    echo -e "${YELLOW}\n******************************************************************************************${RESET} ${RED}  KO { ❌  } ${RESET}"
fi

# clean the mess if it exists
if [ -f $path_exe ]; then
    rm $path_exe
fi

if [ -f $path_user_output ]; then
    rm $path_user_output
fi

if [ -f $path_diff_output ]; then
    rm $path_diff_output
fi

if [ -f $path_norm_output ]; then
    rm $path_norm_output
fi
exit $status
