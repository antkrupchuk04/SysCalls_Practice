#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int p_id;

    if((p_id = fork()) < 0)
    {
        perror("Error creating child process !\n");
        exit(1);
    }

    if(p_id == 0)
    {
        printf("All files in directory (with permissions):\n");
        if(system("ls -Al") < 0)
        {
            perror("Error using command !\n");
            exit(1);
        }
    }

    return 0;
}