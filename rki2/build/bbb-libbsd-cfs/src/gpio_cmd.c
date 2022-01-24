#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <bsp.h> /* for device driver prototypes */
#include <bsp/gpio.h>

#define LED_DELAY  10 

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

  printf("Calling rtems_gpio_request_pin function BBB_P8_10\n");
  sc = rtems_gpio_request_pin(
    BBB_P8_10, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN BBB_P8_10\n");
     return(sc);
  }
  printf("Calling rtems_gpio_request_pin function BBB_P8_12\n");
  sc = rtems_gpio_request_pin(
    BBB_P8_12, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN BBB_P8_12\n");
     return(sc);
  }
  printf("Calling rtems_gpio_request_pin function BBB_P8_14\n");
  sc = rtems_gpio_request_pin(
    BBB_P8_14, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN BBB_P8_14\n");
     return(sc);
  }
  printf("Calling rtems_gpio_request_pin function BBB_P8_16\n");
  sc = rtems_gpio_request_pin(
    BBB_P8_16, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN BBB_P8_16\n");
     return(sc);
  }

  /* Pattern Generation using User Leds */

  for (i = 0; i < 10; i++ )
  {
     /* USER LED 0 */
     rtems_gpio_set(BBB_LED_USR0);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_LED_USR0);
     rtems_task_wake_after(LED_DELAY);

     /* USER LED 1 */
     rtems_gpio_set(BBB_LED_USR1);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_LED_USR1);
     rtems_task_wake_after(LED_DELAY);

     /* USER LED 2 */
     rtems_gpio_set(BBB_LED_USR2);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_LED_USR2);
     rtems_task_wake_after(LED_DELAY);

     /* USER LED 3 */
     rtems_gpio_set(BBB_LED_USR3);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_LED_USR3);
     rtems_task_wake_after(LED_DELAY);

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_10);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_10);
     rtems_task_wake_after(LED_DELAY);

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_12);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_12);
     rtems_task_wake_after(LED_DELAY);

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_14);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_14);
     rtems_task_wake_after(LED_DELAY);

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_16);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_16);
     rtems_task_wake_after(LED_DELAY);
  }
  rtems_gpio_release_pin(BBB_LED_USR0);
  rtems_gpio_release_pin(BBB_LED_USR1);
  rtems_gpio_release_pin(BBB_LED_USR2);
  rtems_gpio_release_pin(BBB_LED_USR3);
  rtems_gpio_release_pin(BBB_P8_10);
  rtems_gpio_release_pin(BBB_P8_12);
  rtems_gpio_release_pin(BBB_P8_14);
  rtems_gpio_release_pin(BBB_P8_16);
  printf("GPIO Test done!\n");  

  return(0);
}


/*
** Test GPIO Command 2
*/
int test_gpio_cmd2( int argc, char *argv[])
{
  int               i;
  rtems_status_code sc;

  printf("Starting Gpio Testing\n");
  
  /* Initializes the GPIO API */
  printf("Calling rtems_gpio_initialize\n");
  rtems_gpio_initialize ();

  printf("Calling rtems_gpio_request_pin function BBB_P8_10\n");
  sc = rtems_gpio_request_pin(
    BBB_P8_10, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN BBB_P8_10\n");
     return(sc);
  }
  printf("Calling rtems_gpio_request_pin function BBB_P8_12\n");
  sc = rtems_gpio_request_pin(
    BBB_P8_12, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN BBB_P8_12\n");
     return(sc);
  }
  printf("Calling rtems_gpio_request_pin function BBB_P8_14\n");
  sc = rtems_gpio_request_pin(
    BBB_P8_14, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN BBB_P8_14\n");
     return(sc);
  }
  printf("Calling rtems_gpio_request_pin function BBB_P8_16\n");
  sc = rtems_gpio_request_pin(
    BBB_P8_16, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN BBB_P8_16\n");
     return(sc);
  }

  /* Pattern Generation using User Leds */

  for (i = 0; i < 10; i++ )
  {
     /* Forward */

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_10);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_10);
     rtems_task_wake_after(LED_DELAY);

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_12);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_12);
     rtems_task_wake_after(LED_DELAY);

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_14);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_14);
     rtems_task_wake_after(LED_DELAY);

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_16);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_16);
     rtems_task_wake_after(LED_DELAY);

     /* Back */

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_16);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_16);
     rtems_task_wake_after(LED_DELAY);

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_14);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_14);
     rtems_task_wake_after(LED_DELAY);

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_12);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_12);
     rtems_task_wake_after(LED_DELAY);

     /* Breadboard LED */
     rtems_gpio_set(BBB_P8_10);
     rtems_task_wake_after(LED_DELAY);
     rtems_gpio_clear(BBB_P8_10);
     rtems_task_wake_after(LED_DELAY);
  }
  rtems_gpio_release_pin(BBB_P8_10);
  rtems_gpio_release_pin(BBB_P8_12);
  rtems_gpio_release_pin(BBB_P8_14);
  rtems_gpio_release_pin(BBB_P8_16);
  printf("GPIO Test done!\n");  

  return(0);
}



/*
** Initialize GPIO Pin
*/
int init_gpio_cmd(int argc, char *argv[])
{
  rtems_status_code sc;

  printf("Initialize GPIO P8_10\n");
  
  /* Initializes the GPIO API */
  printf("Calling rtems_gpio_initialize\n");
  rtems_gpio_initialize ();

  printf("Calling rtems_gpio_request_pin function BBB_P8_10\n");
  sc = rtems_gpio_request_pin(
    BBB_P8_10, DIGITAL_OUTPUT, false, false, NULL);
  if (sc != RTEMS_SUCCESSFUL )
  {
     printf("Failed to request USER PIN BBB_P8_10\n");
     return(sc);
  }
  return(0);
}

/*
** Toggle GPIO on
*/
int toggle_gpio_on_cmd( int argc, char *argv[])
{
  printf("Toggle GPIO P8_10 on\n");
  /* Power Relay GPIO on*/
  rtems_gpio_set(BBB_P8_10);

  return(0);
}

/*
** Toggle GPIO off
*/
int toggle_gpio_off_cmd( int argc, char *argv[])
{
  printf("Toggle GPIO P8_10 off\n");
  /* Power Relay GPIO off */
  rtems_gpio_clear(BBB_P8_10);

  return(0);
}

/*
** Toggle GPIO off
*/
int release_gpio_cmd( int argc, char *argv[])
{
  printf("Release GPIO P8_10 pin\n");
  rtems_gpio_release_pin(BBB_P8_10);
  return(0);
}
