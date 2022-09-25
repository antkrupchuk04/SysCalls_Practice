#include "functions.h"

int write_to_file(int fd)
{
    int rd_count, wt_count;
    char buff[BUFF_SIZE];
    printf("Enter message: \n");
    if(rd_count = read(0, buff, BUFF_SIZE) <= 0 || (wt_count = write(fd, buff, rd_count) <= 0))
    {
        return -1;
    }

    return 0;
}