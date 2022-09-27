#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "functions.h"

int main()
{
    int p_id;

    if((p_id = fork()) == -1)
    {
        perror("Error creating child process !\n");
        exit(1);
    }

    if(p_id == 0)
    {
        print_PIDs();
        system("arch");
    }
    else
    {
        wait(&p_id);
        system("echo \"s(45)\" | bc -l"); 
        system("echo \"s(90)\" | bc -l");
        system("echo \"s(135)\" | bc -l");
        system("echo \"s(180)\" | bc -l");
    }

    return 0;
}