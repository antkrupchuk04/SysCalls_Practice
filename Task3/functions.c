#include "functions.h"

int read_file(int file_descriptor)
{
    char buff[BUFF_SIZE];

    if(read(file_descriptor, buff, BUFF_SIZE) == -1)
    {
        return -1;
    }

    printf("First 512 bytes:\n%s", buff);
    
    return 0;
}

int write_to_file(int file_descriptor)
{
    char buff[BUFF_SIZE];

    fprintf(stdout,"Enter message:\n");
    if(read(1,buff, BUFF_SIZE) == -1)
    {
        return -1;  
    }
    
    if(write(file_descriptor, buff, BUFF_SIZE) == -1)
    {
        return -1;
    }

    return 0;
}