#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFF_SIZE 64

int write_to_file(int fd);

int cp_file_to_file(int fd_from, int fd_to);