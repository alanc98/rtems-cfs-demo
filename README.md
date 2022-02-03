# rtems-cfs-demo
This is the repository for the 2022 FSW Workshop Beaglebone Black RTEMS core Flight System demo. I'm sure there are things that can be improved and fixed in here, but the primary goal of this repository is to be reproducible. I hope that a year or two after the workshop and my demo is given, you could still use this repository to build and run the demo. I think the docker image is key to allowing this to work.

The repository consists of:
- A set of Dockerfiles and scripts to build a docker based RTEMS development kit (docker). Specific commits are used to try to keep the demo from breaking when the RTEMS repositories are updated.
- The RTEMS Kernel Image Project (rki2). This directory has the RTEMS startup code, and it is where the project executable image is created.
- A snapshot of the cFS bundle (cFS). This has forks of the repositories found at: https://github.com/nasa/cFS . Again, the forks here point to specific commits of the submodules, so hopefully as long as the repos exist, this demo can be reproduced.
- The micro SD card files that are needed to boot RTEMS on the beaglebone black (sd-card). The file in this directory need to be copied to a FAT formatted SD card. The partition should also be marked as bootable. The beaglebone black may also try to boot an image from the EMMC chip on the board before it boots the micro SD card.

# Development environment:
You will need to build a RTEMS 6 ARM toolchain, the "beagleboneblack" BSP, and the RTEMS libbsd project for the beaglebone black. I did not intend to cover setting up the RTEMS development environment in this demo, but there are a few options:
- Pull the docker image. You can pull the pre-built docker image in the script run-rtems6-arm-bbb-libbsd.sh. 
- Build the docker image(s). You can also use the helper scripts in the docker directory to build the final docker image locally. You need to build the 4 images in order in the docker directory. 
- Another option is to build your own RTEMS toolchain and BSP without docker. These instructions do not cover how to build a local toolchain, but you can reference the commands in the dockerfiles to see what prerequisites are needed and how to build the toolchain. Otherwise checkout the build toolchain instructions at https://docs.rtems.org

# How to build the demo:
This demo is built in two parts: The cFS and the RTEMS Kernel Image in the rki2 directory. The cFS is built using CMake and produces the following build objects:
- cFE Core object file. This is the unlinked object file that can be dynamicly loaded from the target file system or just linked to an executable. This is very similar to a vxWorks downloadable kernel module.
- cFS Application object files. In this case we have a small set of cFS applications that are built as unlinked loadable objects.
- cFS Table files. These are the binary cFS tables that are loaded at runtime and used by the applications.
- cFS Startup script file. This is a text file that tells the cFE core what cFS apps to start.

The RTEMS Kernel Image is built using a regular Makefile and links the final executable image that is loaded on the board. Earlier it was mentioned that the cFE core is an unlinked object that can either be loaded by this RTEMS image, or the cFE core object can be linked directly in this image. In the case of the Beaglebone and RTEMS ARM architecture, the dynamic loader will not successfully load the cFE core, but it will load simple apps. So in this case we will just link the cFE core object as part of the RTEMS Kernel Image that is loaded on the board. Note that if you try to build the rki2 directory first, the link will fail, because there is no cFE core object. The Makefile copies the cFS application objects, tables, and startup script into a tar image that is unpacked into a RAM disk when RTEMS starts.

## If you are using the Docker image to build: 
I use a helper script to pull and start the toolchain image:
```
$ ./run-rtems6-arm-bbb-libbsd.sh
```

Once you are in the running container's shell, switch to the host directory and you can now build the cFS and RTEMS Kernel Image:
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
## Building with your own RTEMS toolchain:
Before building you may need to change the paths in the cFS CMake toolchain file. There is a path for the Tools and the BSPs. Depending on your setup, they may be the same path. The toolchain file can be found in:
```
cFS/bbb_defs/toolchain-arm-bbb-rtems6.cmake
```

If you changed the paths in the cFS CMake toolchain file, you will also have to change the paths in the RTEMS Kernel Image:
```
rki2/build/rtems-paths.mak
```
I should convert the RTEMS Kernel Image to CMake, so the cFS and rki2 projects can share the same toolchain file. Having two different build systems can introduce errors if the options do not match.

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

## Running the RTEMS image on the Beaglebone black board:

After the rki2 build is complete, the executable image is:
```
rki2/build/bbb-libbsd-cfs/rtems-rki.img
```

This can be copied to the SD card so u-boot can boot the RTEMS + cFS image. Where are the cFS app objects, tables, and startup script? They are bundled in the image in the IMFS + TAR file system that RTEMS will unpack into the RAM disk. I did not intend to document all of the details about running RTEMS on the Beagle here. You may need to consult the RTEMS docs at https://docs.rtems.org.

