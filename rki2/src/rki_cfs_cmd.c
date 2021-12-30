#include <stdio.h>
#include <string.h>
#include <bsp.h>


/* External functions */
int rki_start_cfs(void);

/*
** Start the cFS 
*/
int rki_cfs_command( int argc, char *argv[])
{
   int status;

   status = rki_start_cfs();
   if (status != RTEMS_SUCCESSFUL)
   {
     printf("Error Starting cFS Task\n");
   }
   return(status);
}

