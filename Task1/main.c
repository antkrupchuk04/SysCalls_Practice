#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int file;
    argv[1] = "File.txt";
    const char* command =" df -Th | grep \"^/dev\" > File.txt ";

    if(file = open(argv[1], O_RDWR | O_CREAT) < 0)
    {
        fprintf(stderr, "Erorr ! Can't create file !\n");
        exit(1);
    }

    if(system(command) < 0)
    {
        fprintf(stderr, "Error ! Can't execute command !\n");
        exit(2);
    }

    if(close(file) == -1)
    {
        fprintf(stderr, "Error ! Can't close file !\n");
        exit(3);
    }
    fprintf(stdout, "Program was executed successfully !\n");

    return 0;
}