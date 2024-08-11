#include "../zi_main.h"

/**
 * @brief Calculates the length of the string until the first occurrence of a slash ('/').
 *
 * This function iterates through the characters of the given string until it finds a slash ('/').
 * It returns the index of the first occurrence of a slash, or the length of the string if no slash is found.
 *
 * @param str The input string.
 * @return The index of the first occurrence of a slash, or the length of the string if no slash is found.
 */

int z_len_slash(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '/')
        {
            return (i);
        }
    }
    return (i);
}
