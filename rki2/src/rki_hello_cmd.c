#include <stdio.h>
#include <string.h>

/*
** Hello RTEMS!
*/
int hello_command( int argc, char *argv[])
{
   printf("    ____  ______________  ________ \n");
   printf("   / __ \\/_  __/ ____/  \\/  / ___/ \n");
   printf("  / /_/ / / / / __/ / /\\_/ /\\__ \\  \n"); 
   printf(" / _, _/ / / / /___/ /  / /___/ /  \n"); 
   printf("/_/ \\_| /_/ /_____/_/  /_//____/   \n");
   printf("\n"); 
   printf("Hello RTEMS!\n");
   printf("Create your own command here!\n");

   return(0);
}

