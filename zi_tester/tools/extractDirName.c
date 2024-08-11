#include "../zi_main.h"

/**
 * @brief Extracts the folder name from a given path.
 * 
 * This function takes a path as input and returns the name of the folder in the path.
 * The folder name is extracted by finding the last occurrence of the '/' character in the path.
 * 
 * @param path The path from which to extract the folder name.
 * @return The name of the folder in the path.
 */

char *z_extract_folder_name(char *path)
{
    char *folder_name;
    int ln = z_len_slash(path);
    int i = 0;

    while (path[i] != '\0')
    {
        if (path[i] == '/')
        {
            folder_name = &path[i + 1];
        }
        i++;
    }
    return (folder_name);
}
