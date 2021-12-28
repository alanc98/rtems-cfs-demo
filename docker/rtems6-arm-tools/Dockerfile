FROM rtems6-essential:fsw22 AS build
LABEL Description="rtems6 ARM tool chain"
ENV TERM linux

RUN cd /usr/src && \
    git clone --depth 1 git://git.rtems.org/rtems-source-builder.git rsb && \
    cd /usr/src/rsb && \
    git checkout bb9e049b && \
    ./source-builder/sb-check && \
    cd /usr/src/rsb/rtems && \
    ../source-builder/sb-set-builder --prefix=/opt/rtems6 6/rtems-arm && \
    cd /usr/src && \
    rm -rf rsb

ENV PATH="/opt/rtems6/bin:${PATH}"

