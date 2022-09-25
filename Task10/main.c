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
    const char* home_dir = "/home/antonkrupchuk";
    const char* path_dir1 = "/home/antonkrupchuk/Directory1";
    const char* path_dir2 = "/home/antonkrupchuk/Directory1/Directory2";
    const char* file1_name = "File1.txt";
    const char* file2_name = "File2.txt";
    const char* file1_oldpath = "/home/antonkrupchuk/Directory1/Directory2/File1.txt";
    const char* file1_newpath = "/home/antonkrupchuk/Directory1/File1.txt";
    const char* file2_oldpath = "/home/antonkrupchuk/Directory1/Directory2/File2.txt";
    const char* file2_newpath = "/home/antonkrupchuk/Directory1/File2.txt";

    if(chdir(home_dir) < 0)
    {
        perror("Error changing directory !\n");
        exit(1);
    }
    
    if(mkdir(path_dir1, O_RDWR | O_CREAT) < 0)
    {
        perror("Error creating directory !\n");
        exit(1);
    }

    if(chmod(path_dir1, S_IRWXA) < 0)
    {
        perror("Error changing permissions of directory !\n");
        exit(1);
    }
    
    if(mkdir(path_dir2, O_RDWR | O_CREAT) < 0)
    {
        perror("Error creating directory !\n");
        exit(1);
    }

    if(chmod(path_dir2, S_IRWXA) < 0)
    {
        perror("Error changing permissions of directory !\n");
        exit(1);
    }

    if(chdir(path_dir2) < 0)
    {
        perror("Error changing directory !\n");
        exit(1);
    }

    if((fd1 = open(file1_name, O_RDWR | O_CREAT)) < 0)
    {
        perror("Error opening file !\n");
        exit(1);
    }

    if((fd2 = open(file2_name, O_RDWR | O_CREAT)) < 0)
    {
        perror("Error opening file !\n");
        exit(1);
    }

    if(rename(file1_oldpath, file1_newpath) < 0)
    {
        perror("Error moving file !\n");
        exit(1);
    }
    
    if(rename(file2_oldpath, file2_newpath) < 0)
    {
        perror("Error moving file !\n");
        exit(1);
    }

    if(rmdir(path_dir2) < 0)
    {
        perror("Error removing directory !\n");
        exit(1);
    }

    close(fd1);
    close(fd2);
    printf("Program executed successfully !\n");

    return 0;
}