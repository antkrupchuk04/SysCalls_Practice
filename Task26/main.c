#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "functions.h"

int main()
{
   pid_t p_id1, p_id2;

   if((p_id1 = fork()) < 0)
   {
      perror("Error creating child process !\n");
      exit(1);
   } 

   if(p_id1 == 0)
   {
      printf("Second level process:\n");
      file_size();
   }
   else
   {
      wait(&p_id1);
      
      if((p_id2 = fork()) < 0)
      {
        perror("Error creating child process !\n");
        exit(1);
      }

      if(p_id2 == 0)
      {
        printf("Third level process:\n \tFile system info:\n");
        system("df -H");
      }
   }

   return 0;
}