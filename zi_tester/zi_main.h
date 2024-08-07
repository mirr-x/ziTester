#ifndef ZI_MAIN_H
#define ZI_MAIN_H

/* Libraries ------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/* Structs ---------------------------------------------------*/
typedef struct status_ex_dir
{
    char *ex_folder;
    char *status;
} status_ex_dir;

/* Functions -------------------------------------------------*/
void z_display_Summary_Rusults(status_ex_dir *status_exr);
int z_len_2dArray(char **arr2d);
int z_check_IF_folder_exist(char *name);
void z_print_help();
void z_check_if_im_in_right_dir(char *folder_nm);
int z_len_slash(char *str);
char *z_extract_folder_name(char *path);
void z_test_day_folder(char *folder_nm);
char **get_valid_days_folders(char *exrcices[], int size);
int check_if_ex_folder_exist(char *exrcices[], char *ex_folder, int size);

/* Day 01 Functions ------------------------------------------*/
void z_test_C01_ex_folder(char *ex_folder, status_ex_dir *status_exr, int *pos_ptr);
void zi_TES_C01(); /* here we creat malloc od strructs */
void z_C01_ex00(status_ex_dir *status_exr, int *pos_ptr);
void z_C01_ex01(status_ex_dir *status_exr, int *pos_ptr);
void z_C01_ex02(status_ex_dir *status_exr, int *pos_ptr);
void z_C01_ex03(status_ex_dir *status_exr, int *pos_ptr);
void z_C01_ex06(status_ex_dir *status_exr, int *pos_ptr);

/* Macros -----------------------------------------------------*/
#define MAX_EX_C00 9
#define MAX_FILES 100

/* Colors -----------------------------------------------------*/

/* Color : blue */
const char *blue = "\033[34m";
/* Color : cyan */
const char *cyan = "\033[36m";
/* Color : purple */
const char *purple = "\033[35m";
/* Color : red */
const char *red = "\033[31m";
/* Color : green */
const char *green = "\033[32m";
/* Color : yellow */
const char *yellow = "\033[33m";
/* Color : orange */
const char *orange = "\033[0;33m";
/* Color : bold */
const char *bold = "\033[1m";
/* Color : underline */
const char *underline = "\033[4m";
/* color : pink */
const char *pink = "\033[95m";
/* Color : highlight */
const char *highlight = "\033[7m";
/* Reset color */
const char *reset = "\033[0m";


#endif // ZI_MAIN_H
