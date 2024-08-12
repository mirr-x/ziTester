#include "zi_main.h"

int main(int ac, char *av[])
{
    int i;
    char *folder_nm;

    if (ac == 1)
    {
        /* displaying the help menu */
        z_print_help();
    }
    else if (ac == 2)
    {
        folder_nm = av[1];
        i = z_check_IF_folder_exist(folder_nm);
        if (i == -1)
        {
            printf("%s[❌] Folder Not Found%s\n", red, reset);
        }
        else if (i == 1)
        {
            z_check_if_im_in_right_dir(folder_nm);
        }
    }
    else
    {
        printf("%s\n\t[ ⚠️  ] Too Many Arguments%s\n", yellow, reset);
    }
}


void z_test_day_folder(char *folder_nm)
{
    if (strcmp(folder_nm, "C00") == 0)
    {
        zi_TES_C00();
    }
    else if (strcmp(folder_nm, "C01") == 0)
    {
        zi_TES_C01();
    }
    else if (strcmp(folder_nm, "C02") == 0)
    {
    }
    else if (strcmp(folder_nm, "C03") == 0)
    {
    }
    else if (strcmp(folder_nm, "C04") == 0)
    {
    }
    else if (strcmp(folder_nm, "C05") == 0)
    {
    }
    else if (strcmp(folder_nm, "C06") == 0)
    {
    }
    else if (strcmp(folder_nm, "C07") == 0)
    {
    }
    else if (strcmp(folder_nm, "C08") == 0)
    {
    }
    else if (strcmp(folder_nm, "C09") == 0)
    {
    }
    else if (strcmp(folder_nm, "C10") == 0)
    {
    }
}
