#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include "functions.h"

int main()
{
    if(ls_command() == -1)
    {
        perror("Error executing \"ls_command\" function !\n");
        exit(1);
    }
    printf("Program was executed successfully !\n");

    return 0;
}