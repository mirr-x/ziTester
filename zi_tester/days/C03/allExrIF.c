#include "../../zi_main.h"

/**
 * @brief Executes a specific function based on the given ex_folder parameter.
 *
 * This function takes in an ex_folder parameter and executes a specific function based on its value. The function to be executed depends on the value of ex_folder and is determined using a series of if-else statements. If the ex_folder value matches one of the predefined strings, the corresponding function is called with the status_exr and pos_ptr parameters.
 *
 * @param ex_folder The name of the exercise folder.
 * @param status_exr Pointer to the status_ex_dir structure.
 * @param pos_ptr Pointer to the pos_ptr integer.
 */

void z_test_C03_ex_folder(char *ex_folder, status_ex_dir *status_exr, int *pos_ptr)
{
    if (strcmp(ex_folder, "ex00") == 0)
    {
        z_C03_ex00(status_exr, pos_ptr);
    }
    else if (strcmp(ex_folder, "ex01") == 0)
    {
        z_C03_ex01(status_exr, pos_ptr);
    }
    else if (strcmp(ex_folder, "ex02") == 0)
    {
        z_C03_ex02(status_exr, pos_ptr);
    }
    else if (strcmp(ex_folder, "ex03") == 0)
    {
        z_C03_ex03(status_exr, pos_ptr);
    }
    else if (strcmp(ex_folder, "ex04") == 0)
    {
        z_C03_ex04(status_exr, pos_ptr);
    }
    else if (strcmp(ex_folder, "ex05") == 0)
    {
        z_C03_ex05(status_exr, pos_ptr);
    }

}
