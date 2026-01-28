FROM debian:latest

RUN apt-get update && apt-get install -y \
    git \
    python3 \
    python3-pip \
    sudo \
    build-essential \
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi \
    avrdude \
    dfu-util

RUN python3 -m pip install qmk appdirs --break-system-packages

WORKDIR /root
