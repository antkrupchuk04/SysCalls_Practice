#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "functions.h"

int main(int argc, char** argv)
{
    int fd1, fd2;
    char* file1_name = "File1.txt";
    char* file2_name = "File2.txt";

    if((fd1 = open(file1_name, O_RDWR | O_CREAT)) < 0)
    {
        printf("Error opening file <%s> !\n", file1_name);
        exit(1);
    }

    if((fd2 = open(file2_name, O_RDWR | O_CREAT)) < 0)
    {
        printf("Error opening file <%s> !\n", file2_name);
        exit(1);
    }

    if(write_to_file(fd1) < 0)
    {
        exit(1);
    }

    if(fchmod(fd1, S_IRWXU | S_IRWXO) < 0)
    {
        printf("Error changing file <%s> permissions !\n", file1_name);
        exit(1);
    }

    if(fchmod(fd2, S_IRWXU | S_IRWXO) < 0)
    {
        printf("Error changing file <%s> permissions !\n", file2_name);
        exit(1);
    }

    if(cp_file_to_file(fd1, fd2) == -1)
    {
        perror("Error copying from file to file !\n");
        exit(1);
    } 

    close(fd1);
    close(fd2);

    return 0;
}