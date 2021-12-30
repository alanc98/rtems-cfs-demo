/*
** deps.c 
** 
** This file is used to make sure that functions that are needed by loadable applications get included
** with the kernel image. Normally an RTEMS app only links in the functions that are being referenced.
** In this case, the RTEMS kernel is being built as a separate image from the applications. The applications
** need to call functions that otherwise would not be linked in. This file creates a reference to those 
** functions to be sure that they are included in the RTEMS kernel image. 
**
**
** If you have separately loadable application that links to this kernel image and it has undefined external 
** references, you must put a reference to that function/variable in here. 
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <rtems.h>

extern int __gesf2;
extern int __gtsf2;
extern int __lesf2;
extern int __ltsf2;
extern int __divsf3;
extern int __fixunssfsi;
extern int __floatunsisf;

/*
** Declare the reference to the functions to pull them in
*/
int sleep_ptr = (int)&sleep;
int atol_ptr = (int)&atol;
int cos_ptr = (int)&cos;
int acos_ptr = (int)&acos;
int sin_ptr = (int)&sin;
int asin_ptr = (int)&asin;
int atan_ptr = (int)&atan;
int atan2_ptr = (int)&atan2;
int log_ptr = (int)&log;
int exp_ptr = (int)&exp;
int fmod_ptr = (int)&fmod;
int sqrt_ptr = (int)&sqrt;
int rewinddir_ptr = (int)&rewinddir;


int sinf_ptr = (int)&sinf;
int cosf_ptr = (int)&cosf;
int tanf_ptr = (int)&tanf;
int asinf_ptr = (int)&asinf;
int acosf_ptr = (int)&acosf;
int atanf_ptr = (int)&atanf;
int atan2f_ptr = (int)&atan2f;
int expf_ptr = (int)&expf;
int logf_ptr = (int)&logf;
int powf_ptr = (int)&powf;
int sqrtf_ptr = (int)&sqrtf;
int floorf_ptr = (int)&floorf;
int ceilf_ptr = (int)&ceilf;
int fabsf_ptr = (int)&fabsf;
int fmodf_ptr = (int)&fmodf;

int __gesf2_ptr = (int)&__gesf2;
int __gtsf2_ptr = (int)&__gtsf2;
int __lesf2_ptr = (int)&__lesf2;
int __ltsf2_ptr = (int)&__ltsf2;
int __divsf3_ptr = (int)&__divsf3;
int __fixunssfsi_ptr = (int)&__fixunssfsi;
int __floatunsisf_ptr = (int)&__floatunsisf;

int scanf_ptr = (int)&scanf;
int clock_gettime_ptr = (int)&clock_gettime;

int cfsetospeed_ptr = (int)&cfsetospeed;
int cfsetispeed_ptr = (int)&cfsetispeed;
int cfsetspeed_ptr = (int)&cfsetspeed;
int tcflush_ptr = (int)&tcflush;

int feof_ptr = (int)&feof;

int bind_ptr = (int)&bind;

int rtems_timer_reset_ptr = (int)&rtems_timer_reset;
int rtems_timer_fire_after_ptr = (int)&rtems_timer_fire_after;
int rtems_timer_create_ptr = (int)&rtems_timer_create;
int rtems_task_set_priority_ptr = (int)&rtems_task_set_priority;
/* int rtems_task_variable_add_ptr = (int)&rtems_task_variable_add; */
int rtems_message_queue_create_ptr = (int)&rtems_message_queue_create;
int rtems_message_queue_delete_ptr = (int)&rtems_message_queue_delete;
int rtems_message_queue_receive_ptr = (int)&rtems_message_queue_receive;
int rtems_message_queue_send_ptr = (int)&rtems_message_queue_send;
int rtems_semaphore_flush_ptr = (int)&rtems_semaphore_flush;
int sysconf_ptr = (int)&sysconf;
int snprintf_ptr = (int)&snprintf;
int sprintf_ptr = (int)&sprintf;
int vsnprintf_ptr = (int)&vsnprintf;
int vsprintf_ptr = (int)&vsprintf;
int remove_ptr = (int)&remove;
int system_ptr = (int)&system;
int rtems_timer_cancel_ptr = (int)&rtems_timer_cancel;
int rtems_timer_delete_ptr = (int)&rtems_timer_delete;
int strstr_ptr = (int)&strstr;
int bzero_ptr = (int)&bzero;
int rtems_io_register_driver_ptr = (int)&rtems_io_register_driver;

