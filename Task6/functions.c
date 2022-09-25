#include "functions.h"

int write_to_file(int fd)
{
    char buf[64];
    int rd_count;

    printf("Enter a message: \n");
    if((rd_count = read(0, buf, BUFF_SIZE)) < 0)
    {
        printf("Error reading !\n");
        return -1;
    }
    
    if((write(fd, buf, rd_count)) < 0)
    {
        printf("Error writting to the file !\n");
        return -1;

    }

    return 0;
}