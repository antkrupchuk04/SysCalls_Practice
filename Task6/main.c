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
    char* file_name = "File.txt";
    int fd;

    if((fd = open(file_name, O_RDWR | O_CREAT)) < 0)
    {
        printf("Error opening file !\n");
        exit(1);
    }
    
    if((fchmod(fd, S_IRWXU)) == -1)
    {
        printf("Error changing permissions !\n");
        exit(2);
    }

    if(write_to_file(fd) == -1)
    {
        exit(3);
    }

    close(fd);
}