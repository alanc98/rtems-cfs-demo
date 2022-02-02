# rtems-cfs-demo
This is the repository for the 2022 FSW Workshop Beaglebone Black RTEMS core Flight System demo.

It consists of:
- A set of Dockerfiles and scripts to build a docker based RTEMS development kit. Specific commits are used to try to keep the demo from breaking when the RTEMS repositories are updated.
- The RTEMS Kernel Image Project (RKI). This has the RTEMS startup code, and it is where the project executable image is created.
- A snapshot of the cFS bundle. This has forks of the repositories found at: https://github.com/nasa/cFS

# Development environment:
You will need to build an RTEMS 6 ARM toolchain, the "beagleboneblack" BSP, and the RTEMS libbsd project. There are a few options here:
- Pull the docker image. You can pull the pre-built docker image in the script run-rtems6-arm-bbb-libbsd.sh. 
- Build the docker image. You can also use the helper scripts in the docker directory to build the final docker image locally. You need to build the 4 images in the docker directory. 
- The last option is to build your own RTEMS toolchain and BSP without docker. These instructions do not cover how to build a local toolchain, but you can reference the commands in the dockerfiles to see what prerequisites are needed and how to build the toolchain.

# How to build:
This demo is built in two parts: The cFS and the RTEMS Kernel Image in the rki2 directory. The cFS is built using CMake and produces the following build objects:
- cFE Core object file. This is the unlinked object file that can be dynamic loaded or linked to an executable.
- cFS Application object files. In this case we have a small set of cFS apps that are built as unlinked loadable objects.
- cFS Table files. These are the binary tables that are loaded at runtime and used by the applications.
- cFS Startup script file.

## If you built your own RTEMS toolchain
Before building you may need to change the path in the cFS CMake toolchain file. It can be found in:
```
cFS/bbb_defs/toolchain-arm-bbb-rtems6.cmake
```

If you changed the path in the cFS CMake toolchain file, you will also have to change the path in the RTEMS Kernel Image:
```
rki2/build/rtems-paths.mak
```

Build the cFS:
```
$ cd cFS
$ make SIMULATION=arm-bbb-rtems6 prep
$ make
$ make install
```

Build the RTEMS Kernel Image:
```
$ cd rki2
$ cd build/bbb-libbsd-cfs
$ make
```

## If you are using the Docker image to build 
I use a helper script to pull and start the toolchain image:
```
$ ./run-rtems6-arm-bbb-libbsd.sh
```

Once you are in the running container shell, switch to the host directory and you can now build the cFS and RTEMS Kernel Image:
```
# cd /host
```

Build the cFS:
```
# cd cFS
# make SIMULATION=arm-bbb-rtems6 prep
# make
# make install
```

Build the RTEMS Kernel Image:
```
# cd rki2
# cd build/bbb-libbsd-cfs
# make
```

## OK, I build the cFS and RTEMS Kernel Image, what do I run?

When everything builds, the image is in:
```
rki2/build/bbb-libbsd-cfs/rtems-rki.img
```

This can be copied to the SD card so u-boot can boot the RTEMS + cFS image. Where are the cFS app objects, tables, and startup script? They are bundled in the image in the IMFS + TAR file system that RTEMS will unpack into the RAM disk.

