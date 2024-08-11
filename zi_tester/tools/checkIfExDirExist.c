#include "../zi_main.h"

/**
 * @brief Check if the specified exercise folder exists in the given array of exercise folders.
 * 
 * This function compares the specified exercise folder with each element in the array of exercise folders.
 * If a match is found, it returns 1 indicating that the folder exists. Otherwise, it returns -1.
 * 
 * @param exrcices The array of exercise folders to search in.
 * @param ex_folder The exercise folder to check for existence.
 * @param size The size of the array of exercise folders.
 * @return Returns 1 if the exercise folder exists in the array, -1 otherwise.
 */

int check_if_ex_folder_exist(char *exrcices[], char *ex_folder, int size)
{
    int i = 0;
    while (i != size)
    {
        if (strcmp(exrcices[i], ex_folder) == 0)
        {
            return (1);
        }
        i++;
    }
    return (-1);
}
