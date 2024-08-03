#include "zi_main.h"

int z_check_IF_folder_exist(char *name);
void z_print_help();

int main(int ac, char *av[])
{
    int i;
    char *folder_nm;

    if (ac == 1)
    {
        /* displaying the help menu */
        print_help();
    }
    else if (ac == 2)
    {
        i = check_IF_folder_exist(av[1]);
        if (i == -1)
        {
            printf("%s[❌] Folder Not Found%s\n", red, reset);
        }
        else if (i == 1)
        {
            folder_nm = av[1];
            z_check_if_im_in_right_dir(folder_nm);
        }
    }
    else
    {
        printf("%s[⚠️] Too Many Arguments%s\n", yellow, reset);
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
    printf("'ziteste' v1.0: A Tester Tool For Students At 42 School By mirr-x && mdbentaleb\n\n"
           "Usage:\n"
           "    ziteste <folder_name>\n\n"
           "Example:\n"
           "    ziteste C05\n");
}

void z_check_if_im_in_right_dir(char *folder_nm)  /* check if im in the right folder that user want to test and then >> go and test the folder */
{
    char path[1024];
    char *ptr = getcwd(path, sizeof(path));
    char *curnt_folder = z_extract_folder_name(ptr);

    if (folder_nm == curnt_folder)
    {
        printf("\t\t\t\t\t\t\t\t%s[✔️] Folder %s Found%s\n", green, folder_nm, reset);
        z_test_day_folder(folder_nm);
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t%s[❌] Folder %s Not Found%s\n", red, folder_nm, reset);
        printf("\t\t > %sPLEASE GO TO A VALID FOLDER AND RETRY%s < \n", yellow, reset);
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
        zi_TES_C00();
    }
    else if (strcmp(folder_nm, "C01") == 0)
    {
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

void zi_TES_C00() /* day : C00 */
{
    char *exrcices[] = {"ex00", "ex01", "ex02", "ex03", "ex04", "ex05", "ex06", "ex07", "ex08"};
    char **curunt_ex_folders = get_valid_days_folders(exrcices, MAX_EX_C00); //@ NEED freeing
    int i = 0;

    // will run an sh file to test this shit
    while (i != MAX_EX_C00)
    {
        if (check_if_ex_folder_exist(exrcices, curunt_ex_folders[i], MAX_EX_C00) == 1)
        {
            printf("\t\t\t%s[✔️] Folder %s Found%s\n", green, curunt_ex_folders[i], reset);
            z_test_C00_ex_folder(curunt_ex_folders[i]);
        }
        else
        {
            printf("\t\t\t%s[❌] Folder %s Not Found%s\n", red, curunt_ex_folders[i], reset);
        }
        i++;
    }
}

void z_C00_ex00()
{
    /* check if file exist */
    if (access("ft_strlen.c", F_OK) == 0)
    {

    }
    else
    {
        printf("- %s[❌] file 'ft_putchar.c' Not Found%s\n", red, reset);
    }
}

void z_test_C00_ex_folder(char *ex_folder)
{
    if (strcmp(ex_folder, "ex00"))
    {
        z_C00_ex00();
    }
    else if (strcmp(ex_folder, "ex01"))
    {
    }
    else if (strcmp(ex_folder, "ex02"))
    {
    }
    else if (strcmp(ex_folder, "ex03"))
    {
    }
    else if (strcmp(ex_folder,"ex04"))
    {
    }
}

//! NEED testing
char **
get_valid_days_folders(char *exrcices[], int size) /* return only Exrcices from the day folder exmpl:(ex00, ex01, ex02...)*/
{
    FILE *file_ptr;
    char line[1035];
    char files[100][100];
    int file_count = 0;
    char **valid_ex_dirs;
    int i, rs, x;
    char *ptr;

    file_ptr = popen("ls", "r");

    while (fgets(line, sizeof(line) - 1, file_ptr) != NULL)
    {
        line[strcspn(line, "\n")] = '\0'; /* rmv '\n */
        strcpy(files[file_count], line);
        file_count++;
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
