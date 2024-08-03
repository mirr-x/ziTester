#!/bin/bash

path_main=/home/$USER/ZiTester/TES_C00/ex06/main.c
path_exe=/home/$USER/ZiTester/TES_C00/ex06/user_exe
path_file=ex00/ft_strlen.c
path_expected_output=/home/$USER/ZiTester/TES_C00/ex06/expected_output
path_user_output=/home/$USER/ZiTester/TES_C00/ex06/user_output
path_diff_output=/home/$USER/ZiTester/TES_C00/ex06/diff_output

# colors
GREEN='\033[32m'
RED='\033[31m'
YELLOW='\033[33m'
RESET='\033[0m'

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
    echo -e "${YELLOW}******************************************************${RESET}"
    echo -e "${GREEN} -> $path_file OK ${RESET}"
else
    status=-1
    echo -e "${YELLOW}******************************************************${RESET}"
    echo -e "${RED} -> $path_file KO ${RESET}"
    echo -e "Here is the diff output \n\t < expected_output | > user_output"
    cat $path_diff_output
fi

echo -e "${YELLOW}******************************************************${RESET}"
# clean the mess
rm $path_exe

exit $status