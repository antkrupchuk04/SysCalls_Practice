#include "functions.h"

int ls_command()
{   
    int choice;

    start:
    printf("1 - Print all files\n2 - Print .txt files\n3 - Print directories\n");
    printf("Make your choice:");
    scanf("%d", &choice);
    switch(choice)
    {
        case(1):
        {
            printf("All files in directory:\n");
            if(system("ls -lA") == -1)
            {
                return -1;
            }
            break;
        }

        case(2):
        {
            printf(".txt files in directory:\n");
            if(system("ls -l *.txt") == -1)
            {
                return -1;
            }
            break;
        }

        case(3):
        {
            printf("Directories is directory:\n");
            if(system("ls -l -d */") == -1)
            {
                return -1;
            }
            break;
        }

        default:
        {
            printf("Please choose number 1 - 3 !\n\n");
            goto start;
        }
    }

    return 0;

}