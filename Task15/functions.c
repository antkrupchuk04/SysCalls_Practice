#include "functions.h"

int ps_command()
{
    int choice;

    start:
    printf("1 - User processes\n2 - All processes\n3 - Processes in diapason\n");
    printf("Make your choice:");
    scanf("%d", &choice);

    switch(choice)
    {
        case(1):
        {
            printf("User Processes:\n");
            if(system("ps -u") == -1)
            {
                return -1;
            }
            break;
        }
        
        case(2): 
        {
            printf("All Processes:\n");
            if(system("ps -A") == -1)
            {
                return -1;
            }
            break;
        }
        

        case(3):
        {
            printf("Processes in PID diapason (1 - 1000): \n");
            if(system("ps -p {1..1000}") == -1)
            {
                return -1;
            }
            break;
        }

        default:
        {
            printf("Please choose function (1 - 3) !\n\n");
            goto start;
        }
    }

    return 0;
}