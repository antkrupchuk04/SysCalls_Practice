#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "functions.h"

int main()
{
    int p_id;
    int fd[2];

    if(pipe(fd) < 0)
    {
        printf("Error opening a pipe !\n");
        exit(1);
    }

    if((p_id = fork()) < 0)
    {
        perror("Error creating child process !\n");
        exit(1);
    }

    if(p_id == 0)
    {   
        int child_pid = getpid();
        write(fd[1], &child_pid, sizeof(int));
        if(system("ls -l") == -1)
        {
            perror("Error using command \" ls -l \" !\n");
            exit(1);
        }
        close(fd[1]);
        close(fd[0]);
    }
    else
    {
        wait(&p_id);
        
        int child_pid;
        read(fd[0], &child_pid, sizeof(int));
        printf("Child PID: %d \n", child_pid);
        
        close(fd[0]);
        close(fd[1]);
    }

    return 0;
}