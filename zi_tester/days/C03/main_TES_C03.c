#include "../../zi_main.h"

/**
 * @brief Executes the TES_C03 function.
 * 
 * This function is responsible for executing the TES_C03 function, which performs a series of operations on a set of exercise folders.
 * It retrieves the valid exercise folders using the get_valid_days_folders function and displays them.
 * Then, it checks if each exercise folder exists using the check_if_ex_folder_exist function.
 * If an exercise folder is found, it prints a success message and calls the z_test_C03_ex_folder function to perform further operations.
 * If an exercise folder is not found, it prints a failure message.
 * After processing all exercise folders, it displays the summary results using the z_display_Summary_Rusults function.
 * Finally, it frees the memory allocated for the exercise folders.
 * 
 * @note The get_valid_days_folders, check_if_ex_folder_exist, z_test_C03_ex_folder, and z_display_Summary_Rusults functions are assumed to be defined elsewhere.
 * 
 * @param None
 * @return None
 */

void zi_TES_C03() /* day : C03 */
{
    char *exrcices[] = {"ex00", "ex01", "ex02", "ex03", "ex04", "ex05"};
    char **curunt_ex_folders = get_valid_days_folders(exrcices, MAX_EX_C03); //@ NEED freeing
    /* dislay curunt ex folders*/

    int i = 0;
    int len_ex_folders = 0;
    while (curunt_ex_folders[len_ex_folders] != NULL)
    {
        len_ex_folders++;
    }
    status_ex_dir *status_exr = malloc((sizeof(status_ex_dir) * (len_ex_folders + 1)));
    if (status_exr == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    int pos = 0;
    //@ im hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
    while (curunt_ex_folders[i] != NULL)
    {
        if (check_if_ex_folder_exist(exrcices, curunt_ex_folders[i], MAX_EX_C03) == 1)
        {
            printf("\t\t\t%s---------------------------%s\n", purple, reset);
            printf("\t\t\t%s| [ ✔️ ] Folder %s Found |%s\n", purple, curunt_ex_folders[i], reset);
            printf("%s--------------------------------------------------------------------------%s\n", purple, reset);
            z_test_C03_ex_folder(curunt_ex_folders[i], status_exr, &pos);
        }
        else
        {
            printf("\t\t\t%s[❌] Folder %s Not Found%s\n", red, curunt_ex_folders[i], reset);
        }
        i++;
    }
    status_exr[pos].ex_folder = NULL;
    status_exr[pos].status = NULL;
    z_display_Summary_Rusults(status_exr);

    i = 0;
    while (curunt_ex_folders[i] != NULL) //@ freeing
    {
        free(curunt_ex_folders[i]);
        i++;
    }
    free(curunt_ex_folders);
}
