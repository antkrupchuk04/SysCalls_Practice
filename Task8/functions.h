#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define GRP_PERM S_IRGRP | S_IXGRP
#define OTH_PERM S_IROTH | S_IXOTH
