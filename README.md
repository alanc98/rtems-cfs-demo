# rtems-cfs-demo
This is the repository for the 2022 FSW Workshop Beaglebone Black RTEMS core Flight System demo.

It consists of:
- A set of Dockerfiles and scripts to build a docker based RTEMS development kit. Specific commits are used to try to keep the demo from breaking when the RTEMS repositories are updated.
- The RTEMS Kernel Image Project (RKI). This has the RTEMS startup code, and it is where the project executable image is created.
- A snapshot of the cFS bundle. This has forks of the repositories found at: https://github.com/nasa/cFS

# Development environment. 
You will need to build an RTEMS 6 ARM toolchain, the "beagleboneblack" BSP, and the RTEMS libbsd project. There are a few options here:
- Pull the docker image. You can pull the pre-built docker image in the script run-rtems6-arm-bbb-libbsd.sh. 
- Build the docker image. You can also use the helper scripts in the docker directory to build the final docker image locally. You need to build the 4 images in the docker directory. 
- The last option is to build your own RTEMS toolchain and BSP without docker. These instructions do not cover how to build a local toolchain, but you can reference the commands in the dockerfiles.

# How to build

