#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

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
        int child_PID = getpid();
        system("ls -l");
        printf("Killed PID: %d\n", child_PID);
        if(kill(child_PID, 9) != 0)
        {
            perror("Error killing process !\n");
            exit(1);
        }
    }

    return 0;
}