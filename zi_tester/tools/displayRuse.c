#include "../zi_main.h"

/**
 * @brief Displays the summary results of the status_ex_dir structure.
 *
 * This function takes a pointer to a status_ex_dir structure and displays the summary results.
 * It iterates through the structure array and prints the ex_folder and status values.
 * The function also frees the memory allocated for the status_exr structure.
 *
 * @param status_exr A pointer to the status_ex_dir structure.
 */

void z_display_Summary_Rusults(status_ex_dir *status_exr)
{
    int i = 0;
    int j = 0;

    printf("\n\t\t%s[ 📊 ] SUMMARY RESULTS%s\n", pink, reset);
    printf("%sx────────────────────────────────────────────────────────────x%s\n", purple, reset);
    while (status_exr[i].ex_folder != NULL && status_exr[i].status != NULL)
    {
        printf("%-30s :\t %s \n", status_exr[i].ex_folder, status_exr[i].status);
        i++;
    }
    printf("%sx────────────────────────────────────────────────────────────x%s\n", purple, reset);

    free(status_exr);
}
