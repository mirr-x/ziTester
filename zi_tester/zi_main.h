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
void z_C01_ex04(status_ex_dir *status_exr, int *pos_ptr);
void z_C01_ex05(status_ex_dir *status_exr, int *pos_ptr);
void z_C01_ex06(status_ex_dir *status_exr, int *pos_ptr);
void z_C01_ex07(status_ex_dir *status_exr, int *pos_ptr);
void z_C01_ex08(status_ex_dir *status_exr, int *pos_ptr);

/* Day 00 Functions ------------------------------------------*/
//! CNT
void z_test_C00_ex_folder(char *ex_folder, status_ex_dir *status_exr, int *pos_ptr);
void zi_TES_C00(); /* here we creat malloc od strructs */
void z_C00_ex00(status_ex_dir *status_exr, int *pos_ptr);
void z_C00_ex01(status_ex_dir *status_exr, int *pos_ptr);
void z_C00_ex02(status_ex_dir *status_exr, int *pos_ptr);
void z_C00_ex03(status_ex_dir *status_exr, int *pos_ptr);
void z_C00_ex04(status_ex_dir *status_exr, int *pos_ptr);
void z_C00_ex05(status_ex_dir *status_exr, int *pos_ptr);
void z_C00_ex06(status_ex_dir *status_exr, int *pos_ptr);
void z_C00_ex07(status_ex_dir *status_exr, int *pos_ptr);
void z_C00_ex08(status_ex_dir *status_exr, int *pos_ptr);

/* Macros -----------------------------------------------------*/
#define MAX_EX_C00 9
#define MAX_EX_C01 9
#define MAX_FILES 100

/* Colors -----------------------------------------------------*/
extern const char *blue;
extern const char *cyan;
extern const char *purple;
extern const char *red;
extern const char *green;
extern const char *yellow;
extern const char *orange;
extern const char *bold;
extern const char *underline;
extern const char *pink;
extern const char *highlight;
extern const char *reset;

#endif // ZI_MAIN_H
