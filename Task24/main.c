#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

#include "functions.h"

int main()
{
    pid_t p_id;

    if((p_id = fork()) < 0)
    {
        perror("Error creating child process !\n");
        exit(1);
    }

    if(p_id == 0)
    {
        printf("Child Process <%d> is runnin...\n", getpid());
        kill(getpid(), 9);
    }
    else
    {
        system("wait");
        printf("Closed child PID: %d\n", p_id);
    }

    return 0;
}