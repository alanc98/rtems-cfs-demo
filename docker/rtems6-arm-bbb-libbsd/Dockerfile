FROM rtems6-arm-bbb:fsw22 AS build
LABEL Description="rtems6 bbb libbsd"
ENV TERM linux

RUN cd /usr/src && \
    git clone git://git.rtems.org/rtems-libbsd.git -b 6-freebsd-12 rtems-libbsd && \
    cd rtems-libbsd && \
    git checkout 19d9fde1 && \
    git submodule init && \
    git submodule update && \
    ./waf configure --prefix="/opt/rtems6" \
    --rtems-tools="/opt/rtems6" \
    --rtems-bsps=arm/beagleboneblack \
    --buildset=buildset/default.ini && \
    ./waf && \
    ./waf install && \
    cd .. && \
    rm -rf rtems-libbsd
