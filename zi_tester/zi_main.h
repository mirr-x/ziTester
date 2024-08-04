#ifndef ZI_MAIN_H
#define ZI_MAIN_H

/* libs */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

/* functions */
int z_check_IF_folder_exist(char *name);
void z_print_help();
void z_check_if_im_in_right_dir(char *folder_nm);
int z_len_slash(char *str);
char *z_extract_folder_name(char *path);
void z_test_day_folder(char *folder_nm);
char **get_valid_days_folders(char *exrcices[], int size);
int check_if_ex_folder_exist(char *exrcices[], char *ex_folder, int size);
/* day 01 */
void z_test_C01_ex_folder(char *ex_folder);
void zi_TES_C01();
void z_C01_ex00();
void z_C01_ex01();
void z_C01_ex02();
void z_C01_ex03();
void z_C01_ex06();

/* macros */
#define MAX_EX_C00 9
#define MAX_FILES 100



/* color : blue */
const char *blue = "\033[34m";
/* color : cyan */
const char *cyan = "\033[36m";
/* color :purple */
const char *purple = "\033[35m";
/* color : red */
const char *red = "\033[31m";
/* color : green */
const char *green = "\033[32m";
/* color : yellow */
const char *yellow = "\033[33m";
/* to what you want to color */
const char *reset = "\033[0m";

#endif 