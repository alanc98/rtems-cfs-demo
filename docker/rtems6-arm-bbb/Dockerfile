FROM rtems6-arm-tools:fsw22 AS build
LABEL Description="rtems6 BeagleBone Black bsp"
ENV TERM linux
COPY config.ini /config.ini
RUN cd /usr/src && \
    git clone --depth 1 git://git.rtems.org/rtems.git rtems && \
    cd rtems && \
    git checkout 86579869 && \
    mv /config.ini . && \
    ./waf configure \
    --prefix=/opt/rtems6 && \
    ./waf && \
    ./waf install
