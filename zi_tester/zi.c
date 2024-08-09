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

char **get_valid_days_folders(char *exrcices[], int size) /* return only Exrcices from the day folder exmpl:(ex00, ex01, ex02...)*/
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

void z_display_Summary_Rusults(status_ex_dir *status_exr)
{
    int i = 0;
    int j = 0;

    printf("\n\t\t%s[ 📊 ] SUMMARY RESULTS%s\n", pink, reset);
    printf("%sx────────────────────────────────────────────────────────────x%s\n", purple, reset);
    while (status_exr[i].ex_folder != NULL && status_exr[i].status != NULL)
    {
        printf("%-30s :\t %s \n", status_exr[i].ex_folder, status_exr[i].status);
        i++;
    }
    printf("%sx────────────────────────────────────────────────────────────x%s\n", purple, reset);

    free(status_exr);
}
