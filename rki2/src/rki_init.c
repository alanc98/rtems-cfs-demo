/*
 * RTEMS configuration/initialization
 *
 * Based on code by W. Eric Norum and others
 *
 * This program may be distributed and used for any purpose.
 * I ask only that you:
 *	1. Leave this author information intact.
 *	2. Document any changes you make.
 *
 * W. Eric Norum
 * Saskatchewan Accelerator Laboratory
 * University of Saskatchewan
 * Saskatoon, Saskatchewan, CANADA
 * eric@skatter.usask.ca
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "rki_config.h"
#include "rtems_config.h"
#include <rtems.h>
#include <rtems/version.h>

#ifdef RKI_INCLUDE_TARFS
   /*
   ** Tar file symbols
   */
   extern int _binary_tarfile_start;
   extern int _binary_tarfile_size;
   #define TARFILE_START _binary_tarfile_start
   #define TARFILE_SIZE _binary_tarfile_size
#endif

/*
** External functions
*/
int  rki_init_libbsd( void );
int  rki_add_local_cmds(void);
int  rki_setup_filesystems (void);
void rki_start_network_services(void);

/*
** RTEMS Startup Task
*/
rtems_task Init (rtems_task_argument ignored)
{
   int status;

   printf("\n\n");
#ifdef RKI_INCLUDE_LIBBSD
   printf("RTEMS Kernel Image With LibBSD Booting\n");
#else
   printf("RTEMS Kernel Image Booting\n");
#endif

   printf( "\n\n*** RTEMS Info ***\n" );
   printf("%s\n\n", rtems_version() );
   printf("\n");
   printf(" BSP Ticks Per Second = %d\n",(int)rtems_clock_get_ticks_per_second());
   printf( "*** End RTEMS info ***\n\n" );

#ifdef RKI_INCLUDE_TARFS
   /*
   ** Initialize the file system
   */
   printf("Populating Root file system from TAR file.\n");
   status = Untar_FromMemory(
                (unsigned char *)(&TARFILE_START),
		(unsigned long)&TARFILE_SIZE);
#endif

   /*
   ** Setup the filesystems and commands
   */
   printf("Setting up filesystems.\n");
   status = rki_setup_filesystems();

#ifdef RKI_INCLUDE_LIBBSD
   status = rki_init_libbsd();
#endif

#ifdef RKI_INCLUDE_NETWORK_SERVICES
   /*
   ** Start network services
   */
   rki_start_network_services();
#endif

#ifdef RKI_INCLUDE_SHELL
   /*
   ** Setup the RTEMS shell and add local commands
   */
   printf("Initializing Local Commands.\n");
   status = rki_add_local_cmds();
#endif

   /*
   ** Delete the init task
   ** -- Note, the shell init does not return so the following is not called  
   */
   printf("Ending the RTEMS Init task.\n");
   status = rtems_task_delete( RTEMS_SELF );    /* should not return */
   printf( "rtems_task_delete returned with status of %d.\n", status );
   exit( 1 );
}
