#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <bsp.h> /* for device driver prototypes */
#include <bsp/gpio.h>


static void inline delay_sec(int sec)
{
  rtems_task_wake_after(sec*rtems_clock_get_ticks_per_second());
}


/*
** Test GPIO Command 
*/
int test_gpio_cmd( int argc, char *argv[])
{
  int               i;
  rtems_status_code sc;

  printf("Starting Gpio Testing\n");
  
  /* Initializes the GPIO API */
  printf("Calling rtems_gpio_initialize\n");
  rtems_gpio_initialize ();

  printf("Calling rtems_gpio_request_pin function LED USER 0\n");
  sc = rtems_gpio_request_pin(
    BBB_LED_USR0, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN 0\n");
     return(sc);
  }

  printf("Calling rtems_gpio_request_pin function LED USER 1\n");
  sc = rtems_gpio_request_pin(
    BBB_LED_USR1, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN 1\n");
     return(sc);
  }

  printf("Calling rtems_gpio_request_pin function LED USER 2\n");
  sc = rtems_gpio_request_pin(
    BBB_LED_USR2, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN 2\n");
     return(sc);
  }

  printf("Calling rtems_gpio_request_pin function LED USER 3\n");
  sc = rtems_gpio_request_pin(
    BBB_LED_USR3, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN 3\n");
     return(sc);
  }

  printf("Calling rtems_gpio_request_pin function BBB_P9_41\n");
  sc = rtems_gpio_request_pin(
    BBB_P9_41, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN BBB_P9_41\n");
     return(sc);
  }
  /* Pattern Generation using User Leds */

  for (i = 0; i < 10; i++ )
  {
     /* USER LED 0 */
     rtems_gpio_set(BBB_LED_USR0);
     rtems_task_wake_after(25);
     rtems_gpio_clear(BBB_LED_USR0);
     rtems_task_wake_after(25);

     /* USER LED 1 */
     rtems_gpio_set(BBB_LED_USR1);
     rtems_task_wake_after(25);
     rtems_gpio_clear(BBB_LED_USR1);
     rtems_task_wake_after(25);

     /* USER LED 2 */
     rtems_gpio_set(BBB_LED_USR2);
     rtems_task_wake_after(25);
     rtems_gpio_clear(BBB_LED_USR2);
     rtems_task_wake_after(25);

     /* USER LED 3 */
     rtems_gpio_set(BBB_LED_USR3);
     rtems_task_wake_after(25);
     rtems_gpio_clear(BBB_LED_USR3);
     rtems_task_wake_after(25);

     /* Breadboard LED */
     rtems_gpio_set(BBB_P9_41);
     rtems_task_wake_after(25);
     rtems_gpio_clear(BBB_P9_41);
     rtems_task_wake_after(25);
  }
  rtems_gpio_release_pin(BBB_LED_USR0);
  rtems_gpio_release_pin(BBB_LED_USR1);
  rtems_gpio_release_pin(BBB_LED_USR2);
  rtems_gpio_release_pin(BBB_LED_USR3);
  rtems_gpio_release_pin(BBB_P9_41);
  printf("GPIO Test done!\n");  

  return(0);
}

/*
** Initialize GPIO Pin
*/
int init_gpio_cmd(int argc, char *argv[])
{
  rtems_status_code sc;

  printf("Initialize GPIO P9_41\n");
  
  /* Initializes the GPIO API */
  printf("Calling rtems_gpio_initialize\n");
  rtems_gpio_initialize ();

  printf("Calling rtems_gpio_request_pin function BBB_P9_41\n");
  sc = rtems_gpio_request_pin(
    BBB_P9_41, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN BBB_P9_41\n");
     return(sc);
  }
  return(0);
}

/*
** Toggle GPIO on
*/
int toggle_gpio_on_cmd( int argc, char *argv[])
{
  printf("Toggle GPIO P9_41 on\n");
  /* Power Relay GPIO on*/
  rtems_gpio_set(BBB_P9_41);

  return(0);
}

/*
** Toggle GPIO off
*/
int toggle_gpio_off_cmd( int argc, char *argv[])
{
  printf("Toggle GPIO P9_41 off\n");
  /* Power Relay GPIO off */
  rtems_gpio_clear(BBB_P9_41);

  return(0);
}

/*
** Toggle GPIO off
*/
int release_gpio_cmd( int argc, char *argv[])
{
  printf("Release GPIO P9_41 pin\n");
  rtems_gpio_release_pin(BBB_P9_41);
  return(0);
}
