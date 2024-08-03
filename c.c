#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    // Command to run the shell script
    const char *command = "/home/mirr/Desktop/amirx/github/me/13_pool_tester/TES_C00/ex06/tes_ft_strlen.sh";

    // Execute the shell script
    int status = system(command);

    // Check if the script executed successfully
    if (status == -1)
    {
        perror("system");
        return 1;
    }

    // Optionally, check the exit status of the script
    if (WIFEXITED(status))
    {
        printf("Script exited with status %d\n", WEXITSTATUS(status));
    }
    else
    {
        printf("Script did not terminate normally\n");
    }

    return 0;
}
