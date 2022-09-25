#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "functions.h"

int main(int argc, char* argv[])
{
   int fd, p_id, rd_count;
   const char* file_name = "File.txt";
   const char* path = "/home/antonkrupchuk/OS-Practice/Git_SysCallsPractice/Task5/File.txt";  
   char buf[BUFF_SIZE];
  
   if((p_id = fork()) == -1)
   {
      fprintf(stderr, "Error creating child process !\n");
   }
   
   if(p_id == 0)
   {
      if((fd = open(file_name, O_RDWR)) < 0)
      {
         fprintf(stderr, "Error ! Can't open file <%s> !\n", file_name);
         exit(1);
      }
      rd_count = read(0, buf, BUFF_SIZE);
      write(fd, buf, rd_count);
      close(fd);
   }
   else
   {
      wait(&p_id);
      if((fd = open(file_name, O_RDWR)) < 0)
      {
         fprintf(stderr, "Error ! Can't open file <%s> !\n", file_name);
         exit(1);
      }
      if(chmod(path, S_IRWXU) == -1)
      {
         fprintf(stderr, "Error ! Can't change permissions of file <%s> !\n", file_name);
         exit(2);
      }
      close(fd);
   }
   
   return 0;
}