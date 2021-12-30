/*
** RTEMS Kernel Image Target command setup 
**
*/
#include "rki_config.h"

#include <stdio.h>
#include <stdlib.h>
#include <bsp.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#include <rtems/shell.h>
#include <rtems/bdbuf.h>
#include <rtems/error.h>

/*
** External functions
*/

void rki_add_target_cmds(void);
int  test_gpio_cmd( int argc, char *argv[]);
int  init_gpio_cmd( int argc, char *argv[]);
int  toggle_gpio_on_cmd( int argc, char *argv[]);
int  toggle_gpio_off_cmd( int argc, char *argv[]);
int  release_gpio_cmd( int argc, char *argv[]);

/*
** function to start the shell and add new commands.
*/
void rki_add_target_cmds(void)
{
   printf("Adding Target specific commands\n");
   rtems_shell_add_cmd("gptest"   ,"misc","GPIO Test",test_gpio_cmd);
   rtems_shell_add_cmd("gpinit"   ,"misc","Init GPIO Pin",init_gpio_cmd);
   rtems_shell_add_cmd("gpon"     ,"misc","Turn GPIO Pin On",toggle_gpio_on_cmd);
   rtems_shell_add_cmd("gpoff"    ,"misc","Turn GPIO Pin Off",toggle_gpio_off_cmd);
   rtems_shell_add_cmd("gprelease","misc","Release GPIO Pin",release_gpio_cmd);
}
