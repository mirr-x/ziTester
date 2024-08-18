#include "../../zi_main.h"

/**
 * @brief Checks the status of a specific exercise directory and updates the status_exr array accordingly.
 *
 * This function takes a pointer to a status_ex_dir struct and a pointer to an integer as parameters.
 * It checks the status of the exercise directory specified by the folder variable and updates the status_exr array based on the results.
 *
 * @param status_exr A pointer to a status_ex_dir struct that holds the status of exercise directories.
 * @param pos_ptr A pointer to an integer that keeps track of the position in the status_exr array.
 */

void z_C02_ex00(status_ex_dir *status_exr, int *pos_ptr)
{
    char *folder = "ex00";
    char *file = "ft_strcpy.c";
    char *sh_file = "/home/$USER/ziTester/testing_days_sh/C02/ex00/tes_ft_strcpy.sh";
    char *path_file = "ex00/ft_strcpy.c";
    // not--------------------------------------------
    DIR *dir = opendir(folder);
    if (dir)
    {
        int file_count = 0;
        struct dirent *entry;
        struct stat file_stat;
        char filepath[512]; // Buffer to hold the file path

        while ((entry = readdir(dir)) != NULL)
        {
            snprintf(filepath, sizeof(filepath), "%s/%s", folder, entry->d_name);
            if (stat(filepath, &file_stat) == 0)
            {
                if (S_ISREG(file_stat.st_mode))
                {
                    file_count++;
                }
            }
        }
        closedir(dir);

        if (file_count > 1)
        {
            printf("%s\t\t[ ⚠️  ]  many [f/d] found in %s %s\n\n", yellow, folder, reset);
        }
    }
    //--------------------------------------------------------------------------------------

    /* check if file exist */
    if (access(path_file, F_OK) == 0)
    {
        // will run an sh file to test this shit
        //@ cotinnue here
        int status = system(sh_file);
        int exit_status = WEXITSTATUS(status);
        if (exit_status == 1)
        {
            status_exr[*pos_ptr].ex_folder = path_file;
            status_exr[*pos_ptr].status = "✅  \033[32mPassed\033[0m";
            (*pos_ptr)++;
        }
        else
        {
            status_exr[*pos_ptr].ex_folder = path_file;
            status_exr[*pos_ptr].status = "❌ \033[31mNot Passed\033[0m";
            (*pos_ptr)++;
        }
    }
    else
    {
        printf("%s -> %s NF%s\n", red, path_file, reset);
        printf("%s\n******************************************************************************************%s %s  KO  { ❌  } %s\n", yellow, reset, red, reset);
        status_exr[*pos_ptr].ex_folder = path_file;
        status_exr[*pos_ptr].status = "⚠️  \033[33mfile Not Found\033[0m";
        (*pos_ptr)++;
    }
}
