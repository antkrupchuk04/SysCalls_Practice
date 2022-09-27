#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include "functions.h"

int main()
{
    pid_t p_id1, p_id2;
    printf("\n1.1 Root PID: %d\n\n", getpid());

    if((p_id1 = fork()) < 0)
    {
        perror("Error creating child process !\n");
        exit(1);
    }
    
    if(p_id1 == 0)
    {
        printf("2.1 Child PID: %d\n", getpid());
        printf("2.2 Parent PID: %d\n", getppid());
    }
    else
    {
        system("wait");

        if((p_id2 = fork()) < 0)
        {
            perror("Error creating child process !\n");
            exit(1);
        }

        if(p_id2 == 0)
        {
            printf("3.1 Child PID: %d\n", getpid());
            printf("3.2 Parent PID: %d\n\n", getppid()); 
        }
    }

    return 0;
}