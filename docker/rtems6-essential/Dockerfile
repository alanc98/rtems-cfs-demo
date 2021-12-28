FROM ubuntu:20.04
LABEL Description="RTEMS base build image"
ENV DEBIAN_FRONTEND noninteractive
ENV TERM linux

# Standard build dependencies
RUN apt-get update \
    && apt-get install -y \
       apt-utils build-essential \
       vim u-boot-tools git cmake \
       bison flex texinfo bzip2 \
       xz-utils unzip python \
       libexpat1-dev \
       python-dev zlib1g-dev libtinfo-dev \
    && rm -rf /var/lib/apt/lists/*

