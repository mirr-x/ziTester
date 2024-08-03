#!/bin/bash

path_main=/home/$USER/ZiTester/TES_C00/ex06/main.c
path_exe=/home/$USER/ZiTester/TES_C00/ex06/user_exe
path_file=ex00/ft_strlen.c

gcc -Wall -Wextra -Werror $path_main $path_file -o $path_exe 