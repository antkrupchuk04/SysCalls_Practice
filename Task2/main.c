#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int fd;
    argv[1] = "File.txt";
    const char* command = "uname -r > File.txt";

    if(fd = open(argv[1], O_RDWR | O_CREAT) < 0)
    {
        fprintf(stderr, "Error ! Can't open file !\n");
        exit(1);
    }

    if(system(command) == -1)
    {
        fprintf(stderr, "Error ! Can't execute command !\n");
        exit(2);
    }

    if(close(fd) < 0)
    {
        fprintf(stderr, "Error ! Can't close file !\n");
        exit(3);
    }
    fprintf(stdout, "Program was executed successfully !\n");
    
    return 0;
}