#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFF_SIZE 64

int read_file(int file_descriptor);

int write_to_file(int file_descriptor);