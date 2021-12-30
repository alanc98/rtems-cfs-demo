#include <stdio.h>
#include <string.h>

extern int dhrymain(int);

/*
** Dhrystone Command
*/
int dhrystone_command( int argc, char *argv[])
{
   printf("Running Dhrystone Command!\n");
   dhrymain(10000000);
   printf("Completed Dhrystone\n");
   
   return(0);
}

