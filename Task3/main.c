#include "functions.h"

int main(int argc, char* argv[])
{
    int read_fd, write_fd;
    const char* rd_name = "readfile.txt";
    const char* wt_name = "writefile.txt";

    if((read_fd = open(rd_name, O_RDWR | O_CREAT , 0644)) < 0)
    {
        fprintf(stderr, "Can't open file <%s> !\n", rd_name);
        exit(1);
    }
    if(read_file(read_fd) == -1)
    {
        perror("Error reading file !\n");
        exit(1);
    }
    printf("\n");

    if((write_fd = open(wt_name, O_RDWR | O_CREAT , 0644)) < 0)
    {
        fprintf(stderr,"Can't open file <%s> !\n", wt_name);
        exit(2);
    }

    if(write_to_file(write_fd) < 0)
    {
        fprintf(stderr, "Error writting to a file !\n");
        exit(1);
    }
    close(write_fd);
    close(read_fd);
    printf("\nProgram was executed successfully !\n");

    return 0;
}