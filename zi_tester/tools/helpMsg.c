#include "../zi_main.h"

/**
 * This function checks if a folder with the given name exists.
 * It takes in a parameter 'name' which is the name of the folder to check.
 *
 * @param name The name of the folder to check.
 * @return 1 if the folder exists, -1 otherwise.
 */

void z_print_help()
{
    printf("  %s'ziteste'%s %sv1.0: A Tester Tool For Students At 42 School By: %s%s>%s %smirr-x%s %s<%s %s&&%s %s>%s %smdbentaleb%s %s<%s\n\n"
           "%sUsage:%s\n"
           "%s         ziteste <folder_name>%s\n\n"
           "%sExample:%s\n"
           "%s         ziteste C05%s\n",
           yellow, reset, cyan, reset, yellow, reset, purple, reset, yellow, reset, cyan, reset, yellow, reset, purple, reset, yellow, reset,
           underline, reset, red, reset,
           underline, reset, red, reset);
}
