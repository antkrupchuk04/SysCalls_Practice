#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "functions.h"

int main(int argc, char** argv)
{
    int p_id;

    if((p_id = fork()) < 0)
    {
        perror("Error creating process !\n");
        exit(1);
    }
    if(p_id == 0)
    {
        if(system("ls -l") == -1)
        {
            perror("Error using system command !\n");
            exit(1);
        }

        exit(0);
    }
    else
    {
        printf("Process PID: %d\n", getpid());
        printf("Parent PID: %d\n\n", getppid());
    }

    return 0;
}