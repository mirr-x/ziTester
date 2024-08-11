#include "../zi_main.h"

/**
 * Checks if the current directory matches the specified folder name and performs testing on the folder.
 * 
 * This function checks if the current directory matches the specified folder name. If they match, it prints the current folder name, 
 * performs testing on the folder, and prints the end of the folder message. If they don't match, it prints an error message 
 * indicating that the folder does not exist and prompts the user to navigate to a valid folder.
 * 
 * @param folder_nm The name of the folder to be checked and tested.
 */

void z_check_if_im_in_right_dir(char *folder_nm) /* check if im in the right folder that user want to test and then >> go and test the folder */
{
    char path[1024];
    char *ptr = getcwd(path, sizeof(path));
    char *curnt_folder = z_extract_folder_name(ptr);

        if (strcmp(folder_nm, curnt_folder) == 0)
    {
        printf("%s╔══════════════════════════════════════════════════════════════════════════╗\n", cyan);
        printf("║                       📂 CURRENT FOLDER: %s                             ║\n", curnt_folder);
        printf("╚══════════════════════════════════════════════════════════════════════════╝%s\n\n", reset);
        z_test_day_folder(folder_nm);
        printf("\n\n%s╔══════════════════════════════════════════════════════════════════════════╗\n", cyan);
        printf("║                       📂 END OF FOLDER: %s                              ║\n", curnt_folder);
        printf("╚══════════════════════════════════════════════════════════════════════════╝%s\n\n", reset);
    }
    else
    {
        printf("\n\t\t\t%s[ ❌ ] Folder %s NF%s\n", red, folder_nm, reset);
        printf("\n\n\t\t%sPlease navigate to a valid folder and retry.%s\n\n", yellow, reset);
    }
}
