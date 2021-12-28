This directory contains the resources to create Docker images for the FSW 22 RTEMS cFS Demo on the Beaglebone Black computer.

I chose not to make this a submodule or branch of my RTEMS docker repo here:
https://github.com/alanc98/rtems-docker

The differences are:
- These only have the ARM and BBB images. The demo needs the rtems6-arm-bbb-libbsd image
- The images checkout a specific commit of the RTEMS source builder, RTEMS, and rtems-libbsd repos. I did this to try to make sure the demo would work long after the repo has changed. I did not want the demo to break a month after it was presented.
- The images were tagged with fsw22 to distinguish them from my regular RTEMS docker images.


