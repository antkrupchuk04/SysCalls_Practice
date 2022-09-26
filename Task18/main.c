#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include "functions.h"

int main()
{
    int p_id;

    if((p_id = fork()) < 0)
    {
        perror("Error creating child process !\n");
        exit(1);
    }

    if(p_id == 0)
    {
        if(system("ps -A") == -1)
        {
            perror("Error using command !\n");
            exit(1);
        }
    }
    else
    {

        printf("Parent PID: %d\n", getppid());
        printf("Current PID: %d\n", getpid());
    }

    return 0;
}