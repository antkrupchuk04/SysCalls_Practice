#include "functions.h"

void print_PIDs()
{
    printf("Parent PID: %d\nChild PID: %d\n", getppid(), getpid());

    return;
}