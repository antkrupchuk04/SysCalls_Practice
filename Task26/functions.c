#include "functions.h"

int file_size()
{
    char file_name[NAME_LENGTH];
    char* command;

    printf("\nAll files in directory:\n");
    system("ls -lA");
    
    printf("Enter name of file to check size: \n");
    read(0, file_name, NAME_LENGTH);
    sprintf(command,"du -sh %s",file_name);

    printf("File size:\n");
    system(command);

    return 0;
}