#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#include "functions.h"

int main(int argc, char** argv)
{
    if(ps_command() == -1)
    {
        perror("Error \"ps_command\" function\n");
        exit(1);
    }
    printf("Program was executed successfully !\n");
    
    return 0;
}