/*
** rki_config.h
**
**  Author:  Alan Cudmore
**
**  This contains the configuration settings for an RTEMS Application
**
*/

/*
** Basic configuration settings for the RTEMS Kernel Image ( RKI )
*/

/*
** Include the RTEMS shell and startup script?
*/
#define RKI_INCLUDE_SHELL

/*
** Define the shell init script to run
*/
#define RKI_SHELL_INIT "/shell-init"

/*
** Include the Dynamic Loader commands
** undef if your BSP does not support the loader
*/
#define RKI_INCLUDE_DL_CMDS

/*
** Include support for the "regular" RAM disk
*/
#define RKI_INCLUDE_RAMDISK

/*
** Define RAM Disk 0 base address and size
*/
#define RAM_DISK_0_BASE_ADDR 0x0
#define RAM_DISK_0_BLOCKS    128 * 1024

/*
** Include the TAR file system to initialze IMFS
** This is used to setup the base directories and startup scripts
*/
#define RKI_INCLUDE_TARFS

/*
** Include the heritage RTEMS network stack/driver
*/
#undef RKI_INCLUDE_NETWORK

/*
** Include libbsd - should not be used wth the old network stack
*/
#define RKI_INCLUDE_LIBBSD

/*
** start network services. Enable/disable individual services below
*/
#define RKI_INCLUDE_NETWORK_SERVICES

   /*
   ** Include and start the telnetd server
   */
   #define RKI_INCLUDE_TELNETD_SERVER

   /*
   ** Include and start the RTEMS ftp server
   */
   #define RKI_INCLUDE_FTPSERVER

   /*
   ** Include the NFS client
   */
   #undef RKI_INCLUDE_NFSCLIENT

   /*
   ** Include the TFTP file system
   */
   #undef RKI_INCLUDE_TFTPFS

