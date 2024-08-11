#include "../zi_main.h"

/**
 * This function checks if a folder with the given name exists.
 * It takes in a parameter 'name' which is the name of the folder to check.
 *
 * @param name The name of the folder to check.
 * @return 1 if the folder exists, -1 otherwise.
 */

int z_check_IF_folder_exist(char *name)
{
    char *arr[11] = {"C00", "C01", "C02", "C03", "C04", "C05", "C06", "C07", "C08", "C09", "C10"};
    int i = 0;

    while (i < 11)
    {
        if (strcmp(name, arr[i]) == 0)
        {
            return (1);
        }
        i++;
    }
    return (-1);
}