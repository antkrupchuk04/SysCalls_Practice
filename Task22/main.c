#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "functions.h"

int main()
{
    pid_t p_id;

    if((p_id = fork()) == -1)
    {
        perror("Error creating child process !\n");
        exit(1);
    }

    if(p_id == 0)
    {
        printf("\nArchitecture of system:\n");
        system("arch");
        printf("\n");
    }
    else
    {
        wait(&p_id);
        printf("Exponent (lg(2)*0.5):\n");
        system("echo \'scale=5;e(l(2)*0.5)\' | bc -l");

        printf("Exponent (lg(3)*0.5):\n");
        system("echo \'scale=5;e(l(3)*0.5)\' | bc -l");

        printf("Exponent (lg(3)*0.5):\n");
        system("echo \'scale=5;e(l(4)*0.5)\' | bc -l");

    }

    return 0;
}