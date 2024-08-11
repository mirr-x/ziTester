#include "../zi_main.h"

/**
 * @brief Retrieves the valid days folders.
 *
 * This function retrieves the valid days folders by listing the files in the current directory and filtering them based on the provided exercises.
 *
 * @param exrcices An array of exercise names.
 * @param size The size of the exercise array.
 * @return An array of valid days folders.
 */

char **get_valid_days_folders(char *exrcices[], int size)
{
    FILE *file_ptr;
    char line[100];
    char files[100][100];
    int file_count = 0;
    char **valid_ex_dirs;
    int i, rs, x;
    char *ptr;

    file_ptr = popen("ls", "r");
    if (file_ptr == NULL)
    {
        perror("popen failed");
        exit(1);
    }

    while (fgets(line, sizeof(line) - 1, file_ptr) != NULL)
    {
        line[strcspn(line, "\n")] = '\0'; /* rmv '\n */
        if (file_count <= MAX_FILES)
        {
            strcpy(files[file_count], line);
            file_count++;
        }
        else
        {
            fprintf(stderr, "Warning: too many files, increase MAX_FILES\n");
            break;
        }
    }

    /* close file */
    pclose(file_ptr);

    /* filter folders to only ex */
    valid_ex_dirs = malloc((sizeof(char *) * size) + 1);
    i = 0;
    rs = 0;
    while (i != file_count)
    {
        if (check_if_ex_folder_exist(exrcices, files[i], size) == 1)
        {
            valid_ex_dirs[rs] = strdup(files[i]);
            rs++;
        }
        i++;
    }
    valid_ex_dirs[rs] = NULL;

    return (valid_ex_dirs);
}
