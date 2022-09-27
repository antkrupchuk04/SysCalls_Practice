#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

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
       printf("1.1 (Child) Process PID: %d\n", getpid());
       printf("System Info:\n");
       system("uname -a");
    }
    else
    {
        wait(&p_id);

        int p_id2; 
        printf("1.2 (Parent) Process PID: %d\n\n", getpid());
        
        if((p_id2 = fork()) < 0)
        {
            perror("Error creating child process !\n");
            exit(1);
        }

        if(p_id2 == 0)
        {
            printf("2.1 (Child) Process PID: %d\n", getpid());
            printf("All user processes:\n");
            system("ps -u");
        }
        else
        {
            wait(&p_id2);
            printf("2.2 (Parent) Process PID: %d\n", getpid()); 
        }
    }

    return 0;
}