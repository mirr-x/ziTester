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

void zi_TES_C01() /* day : C01 */
{
    char *exrcices[] = {"ex00", "ex01", "ex02", "ex03", "ex04", "ex05", "ex06", "ex07", "ex08"};
    char **curunt_ex_folders = get_valid_days_folders(exrcices, MAX_EX_C00); //@ NEED freeing
    /* dislay curunt ex folders*/

    int i = 0;
    int len_ex_folders = 0; 
    while (curunt_ex_folders[len_ex_folders] != NULL)
    {
        len_ex_folders++;
    }
    status_ex_dir *status_exr = malloc((sizeof(status_ex_dir) * (len_ex_folders + 1)));
    if (status_exr == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    int pos = 0;
    //@ im hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
    while (curunt_ex_folders[i] != NULL)
    {
        if (check_if_ex_folder_exist(exrcices, curunt_ex_folders[i], MAX_EX_C00) == 1)
        {
            printf("\t\t\t%s---------------------------%s\n", purple, reset);
            printf("\t\t\t%s| [ ✔️ ] Folder %s Found |%s\n", purple, curunt_ex_folders[i], reset);
            printf("%s--------------------------------------------------------------------------%s\n", purple, reset);
            z_test_C01_ex_folder(curunt_ex_folders[i], status_exr, &pos);
        }
        else
        {
            printf("\t\t\t%s[❌] Folder %s Not Found%s\n", red, curunt_ex_folders[i], reset);
        }
        i++;
    }
    status_exr[pos].ex_folder = NULL;
    status_exr[pos].status = NULL;
    z_display_Summary_Rusults(status_exr);

    i = 0;
    while (curunt_ex_folders[i] != NULL) //@ freeing
    {
        free(curunt_ex_folders[i]);
        i++;
    }
    free(curunt_ex_folders);
}

void z_C01_ex00(status_ex_dir *status_exr, int *pos_ptr)
{

    // bhadi ghancheckiw ch7al  mn  file --------------------------------------------
    DIR *dir = opendir("ex00");
    if (dir)
    {
        int file_count = 0;
        struct dirent *entry;
        struct stat file_stat;
        char filepath[512]; // Buffer to hold the file path

        while ((entry = readdir(dir)) != NULL)
        {
            snprintf(filepath, sizeof(filepath), "ex00/%s", entry->d_name);
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
            printf("%s\t\t[ ⚠️  ]  many [f/d] found in ex00 %s\n\n", yellow, reset);
        }
    }
    //--------------------------------------------------------------------------------------
    
    /* check if file exist */
    if (access("ex00/ft_ft.c", F_OK) == 0)
    {
        // will run an sh file to test this shit
        //@ cotinnue here
        int status = system("/home/$USER/ziTester/testing_days_sh/C01/ex00/tes_ft_ft.sh");
        int exit_status = WEXITSTATUS(status);
        if (exit_status == 1)
        {
            status_exr[*pos_ptr].ex_folder = "ex00/ft_ft.c";
            status_exr[*pos_ptr].status = "✅  \033[32mPassed\033[0m";
            (*pos_ptr)++;
        }
        else
        {
            status_exr[*pos_ptr].ex_folder = "ex00/ft_ft.c";
            status_exr[*pos_ptr].status = "❌ \033[31mNot Passed\033[0m";
            (*pos_ptr)++;
        }
    }
    else
    {
        printf("%s -> ex00/ft_ft.c NF%s\n", red, reset);
        printf("%s\n******************************************************************************************%s %s  KO  { ❌  } %s\n", yellow, reset, red, reset);
        status_exr[*pos_ptr].ex_folder = "ex00/ft_ft.c";
        status_exr[*pos_ptr].status = "⚠️  \033[33mfile Not Found\033[0m";
        (*pos_ptr)++;
    }
}

void z_C01_ex01(status_ex_dir *status_exr, int *pos_ptr)
{
    /* check if file exist */
    if (access("ex01/ft_ultimate_ft.c", F_OK) == 0)
    {
        // will run an sh file to test this shit
        //@ cotinnue here
        int status = system("/home/$USER/ziTester/testing_days_sh/C01/ex01/tes_ft_ultimate_ft.sh");
        int exit_status = WEXITSTATUS(status);
        if (exit_status == 1)
        {
            status_exr[*pos_ptr].ex_folder = "ex01/ft_ultimate_ft.c";
            status_exr[*pos_ptr].status = "✅  \033[32mPassed\033[0m";
            (*pos_ptr)++;
        }
        else
        {
            status_exr[*pos_ptr].ex_folder = "ex01/ft_ultimate_ft.c";
            status_exr[*pos_ptr].status = "❌ \033[31mNot Passed\033[0m";
            (*pos_ptr)++;
        }
    }
    else
    {
        printf("%s -> ex01/ft_ultimate_ft.c NF%s\n", red, reset);
        printf("%s\n******************************************************************************************%s %s  KO  { ❌  } %s\n", yellow, reset, red, reset);
        status_exr[*pos_ptr].ex_folder = "ex01/ft_ultimate_ft.c";
        status_exr[*pos_ptr].status = "⚠️  \033[33mfile Not Found\033[0m";
        (*pos_ptr)++;
    }
}

void z_C01_ex02(status_ex_dir *status_exr, int *pos_ptr)
{
    /* check if file exist */
    if (access("ex02/ft_swap.c", F_OK) == 0)
    {
        // will run an sh file to test this shit
        //@ cotinnue here
        int status = system("/home/$USER/ziTester/testing_days_sh/C01/ex02/tes_ft_swap.sh");
        int exit_status = WEXITSTATUS(status);
        if (exit_status == 1)
        {
            status_exr[*pos_ptr].ex_folder = "ex02/ft_swap.c";
            status_exr[*pos_ptr].status = "✅  \033[32mPassed\033[0m";
            (*pos_ptr)++;
        }
        else
        {
            status_exr[*pos_ptr].ex_folder = "ex02/ft_swap.c";
            status_exr[*pos_ptr].status = "❌ \033[31mNot Passed\033[0m";
            (*pos_ptr)++;
        }
    }
    else
    {
        printf("%s -> ex02/ft_swap.c NF%s\n", red, reset);
        printf("%s\n******************************************************************************************%s %s  KO  { ❌  } %s\n", yellow, reset, red, reset);
        status_exr[*pos_ptr].ex_folder = "ex02/ft_swap.c";
        status_exr[*pos_ptr].status = "⚠️  \033[33mfile Not Found\033[0m";
        (*pos_ptr)++;
    }
}

void z_C01_ex03(status_ex_dir *status_exr, int *pos_ptr)
{
    /* check if file exist */
    if (access("ex03/ft_div_mod.c", F_OK) == 0)
    {
        // will run an sh file to test this shit
        //@ cotinnue here
        int status = system("/home/$USER/ziTester/testing_days_sh/C01/ex03/tes_ft_div_mod.sh");
        int exit_status = WEXITSTATUS(status);
        if (exit_status == 1)
        {
            status_exr[*pos_ptr].ex_folder = "ex03/ft_div_mod.c";
            status_exr[*pos_ptr].status = "✅  \033[32mPassed\033[0m";
            (*pos_ptr)++;
        }
        else
        {
            status_exr[*pos_ptr].ex_folder = "ex03/ft_div_mod.c";
            status_exr[*pos_ptr].status = "❌ \033[31mNot Passed\033[0m";
            (*pos_ptr)++;
        }
    }
    else
    {
        printf("%s -> ex03/ft_div_mod.c NF%s\n", red, reset);
        printf("%s\n******************************************************************************************%s %s  KO  { ❌  } %s\n", yellow, reset, red, reset);
        status_exr[*pos_ptr].ex_folder = "ex03/ft_div_mod.c";
        status_exr[*pos_ptr].status = "⚠️  \033[33mfile Not Found\033[0m";
        (*pos_ptr)++;
    }
}

void z_C01_ex06(status_ex_dir *status_exr, int *pos_ptr)
{
    /* check if file exist */
    if (access("ex06/ft_strlen.c", F_OK) == 0)
    {
        // will run an sh file to test this shit
        //@ cotinnue here
        int status = system("/home/$USER/ziTester/testing_days_sh/C01/ex06/tes_ft_strlen.sh");
        int exit_status = WEXITSTATUS(status);
        if (exit_status == 1)
        {
            status_exr[*pos_ptr].ex_folder = "ex06/ft_strlen.c";
            status_exr[*pos_ptr].status = "✅  \033[32mPassed\033[0m";
            (*pos_ptr)++;
        }
        else
        {
            status_exr[*pos_ptr].ex_folder = "ex06/ft_strlen.c";
            status_exr[*pos_ptr].status = "❌ \033[31mNot Passed\033[0m";
            (*pos_ptr)++;
        }
    }
    else
    {
        printf("%s -> ex06/ft_strlen.c NF%s\n", red, reset);
        printf("%s\n******************************************************************************************%s %s  KO  { ❌  } %s\n", yellow, reset, red, reset);
        status_exr[*pos_ptr].ex_folder = "ex06/ft_strlen.c";
        status_exr[*pos_ptr].status = "⚠️  \033[33mfile Not Found\033[0m";
        (*pos_ptr)++;
    }
}

void z_test_C01_ex_folder(char *ex_folder, status_ex_dir *status_exr, int *pos_ptr)
{
    if (strcmp(ex_folder, "ex00") == 0)
    {
        z_C01_ex00(status_exr, pos_ptr);
    }
    else if (strcmp(ex_folder, "ex01") == 0)
    {
        z_C01_ex01(status_exr, pos_ptr);
    }
    else if (strcmp(ex_folder, "ex02") == 0)
    {
        z_C01_ex02(status_exr, pos_ptr);
    }
    else if (strcmp(ex_folder, "ex03") == 0)
    {
        z_C01_ex03(status_exr, pos_ptr);
    }
    else if (strcmp(ex_folder, "ex04") == 0)
    {
        // Add code for ex04
    }
    else if (strcmp(ex_folder, "ex05") == 0)
    {
        // Add code for ex05
    }
    else if (strcmp(ex_folder, "ex06") == 0)
    {
        z_C01_ex06(status_exr, pos_ptr);
    }
    else if (strcmp(ex_folder, "ex07") == 0)
    {
        // Add code for ex07
    }
    else if (strcmp(ex_folder, "ex08") == 0)
    {
        // Add code for ex08
    }
}
