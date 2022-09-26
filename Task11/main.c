#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define S_IRWXA S_IRWXU | S_IRWXG | S_IRWXO

int main(int argc, char** argv)
{
    int fd1, fd2;
    const char* home_path = "/home";
    const char* dir1_path = "/home/directory1";
    const char* dir2_path = "/home/directory1/directory2";
    const char* file1_name = "File1.txt";
    const char* file2_name = "File2.txt";
    const char* cp_command = "cp *.txt /home/directory1";

    if(mkdir(dir1_path, O_RDWR | O_CREAT) < 0 || chmod(dir1_path, S_IRWXA) < 0)
    {
        perror("Error creating directory or changing permissions of directory !\n");
        exit(1);
    }

    if(mkdir(dir2_path, O_RDWR | O_CREAT) < 0 || chmod(dir2_path, S_IRWXA) < 0)
    {
        perror("Error creating directory or changing permissions of directory !\n");
        exit(1);
    }

    if(chdir(dir2_path) < 0)
    {
        perror("Error changing directory !\n");
        exit(1);
    }

    if((fd1 = open(file1_name, O_RDWR | O_CREAT)) < 0 || (fd2 = open(file2_name, O_RDWR | O_CREAT)) < 0)
    {
        perror("Error creating files !\n");
        exit(1);
    }

    if(fchmod(fd1, S_IRWXA) < 0 || fchmod(fd2, S_IRWXA) < 0)
    {
        perror("Error changing permissions of files !\n");
        exit(1);
    }

    if(system(cp_command) < 0)
    {
        perror("Error using command !\n");
        exit(1);
    }
    close(fd1);
    close(fd2);

    printf("Program was executed successfully !\n");
    return 0;
}