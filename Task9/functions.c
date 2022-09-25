#include "functions.h"

int write_to_file(int fd)
{
    char buf[BUFF_SIZE];
    int rd_count, wt_count;
    printf("Enter message: \n");

    if((rd_count = read(0, buf, BUFF_SIZE)) <= 0 || (wt_count = write(fd, buf, rd_count)) <= 0)
    {
        printf("Error reading file or writting to a file !\n");
        return -1;
    }

    return 0;
}

int cp_file_to_file(int fd_from, int fd_to)
{
    int rd_count;
    char buf[BUFF_SIZE];

    if((rd_count = read(fd_from, buf, BUFF_SIZE)) < 0)
    {
        return -1;
    }
   if(write(fd_to, buf, rd_count) < 0)
   {
    return -1;
   }

    return 0;
}