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
    char* path_dir1 = "/home/antonkrupchuk/OS-Practice/Git_SysCallsPractice/Task8/Dir1";
    char* path_dir2 = "/home/antonkrupchuk/OS-Practice/Git_SysCallsPractice/Task8/Dir1/Dir2";
    char* path_file1 = "/home/antonkrupchuk/OS-Practice/Git_SysCallsPractice/Task8/Dir1/Dir2/File1.txt";
    char* path_file2 = "/home/antonkrupchuk/OS-Practice/Git_SysCallsPractice/Task8/Dir1/Dir2/File2.txt";
    
    if(mkdir(path_dir1, O_RDWR) < 0)
    {
        printf("Error creating directory <%s> !\n", path_dir1);
        exit(1);
    }

    if(chmod(path_dir1, S_IRWXU) < 0)
    {
        printf("Error changing permissions of directory !\n");
        exit(1);
    }

    if(mkdir(path_dir2, O_RDWR) < 0)
    {
        printf("Error creating directory <%s> !\n", path_dir2);
        exit(1);
    }

    if(chmod(path_dir2, S_IRWXU) < 0)
    {
        printf("Error changing permissions of directory !\n");
        exit(1);
    }

    if(chdir(path_dir2) < 0)
    {
        printf("Error changing directory !\n");
        exit(1);
    }

    if((fd1 = open("File1.txt", O_RDWR | O_CREAT)) < 0)
    {
        printf("Error opening file <File1.txt> !\n");
        exit(1);
    }

    if((fd2 = open("File2.txt", O_RDWR | O_CREAT)) < 0)
    {
        printf("Error opening file <File2.txt> !\n");
        exit(2);
    }

    if(fchmod(fd1, S_IRWXU | GRP_PERM | OTH_PERM) < 0)
    {
        printf("Error changing file <File1.txt> permissions !\n");
        exit(1);
    }
    if(fchmod(fd2, S_IRWXU | GRP_PERM) < 0)
    {
        printf("Error changing file <File2.txt> permissions !\n");
        exit(0);
    }

    return 0;
}