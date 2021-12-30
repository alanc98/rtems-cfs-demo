# Rtems Kernel Image Project v2 (rki2)

This project provides a starting point or example of how to configure an RTEMS application for your project. There are many ways to configure an RTEMS application, this project is just something I have done to help me run on various targets. It is put together from different examples I have found, most of which have been contributed by RTEMS developers. 

NOTE: The rki2 project is targeted to RTEMS 5 with optional rtems-libbsd integration.

This project configuration provides:

- RAM Disk setup
- Network setup ( if the target supports it )
- Shell setup and shell startup script
- Example shell commands including whetstone and dhrystone benchmarks

Each target can be configured and compiled separately.

You can configure many of the options in the RKI. Take a close look at the following files:

.Config Files
- rtems_config.h
- rki_config.h

How to build
------------

1. Change to the build directory for the target you are interested in building. This example shows Beaglebone Black with rtems-libbsd.

```
$ cd build
$ cd bbb-libbsd
```

2. Double check the options in the Makefile. You usually just need to set the path to the cross compiler and RTEMS BSP.  


```
RTEMS_TOOL_BASE ?= /home/alan/rtems/tools/6
RTEMS_BSP_BASE ?= /home/alan/rtems/bsps/6
```

3. Run make
 
```
$ make 
```

to build the executable.

How to run the RKI image
------------------------

(TBD)

Commands to try
---------------

When you run the application on a target, you should get the shell prompt. Try some of these commands:

.List all tasks

```
# task
```

.List all semaphores

```
# sema
```

.Run the Dhrystone benchmark

```
# dhrystone
```

.Run the Whetstone benchmark
```
# whetstone
```

.Create 5 tasks that run for 10 seconds
```
# taskdemo
```

There are quite a few more commands to run, just type

```
# help
```

You can also add your own commands, and include a startup script 

Check out what the startup script is doing by typing:

```
# cat shell-init
```

In the case of the Raspberry Pi BSP, it formats a 64 Megabyte RAM disk with the RTEMS file system, then mounts the disk on /ram.
