FROM debian:latest

# Install QMK dependencies
RUN apt update && apt install -y \
    git \
    python3 \
    python3-pip \
    sudo \
    gcc-avr \
    binutils-avr \
    avr-libc \
    gcc-arm-none-eabi \
    binutils-arm-none-eabi \
    libnewlib-arm-none-eabi \
    && rm -rf /var/lib/apt/lists/*

# Install QMK CLI
RUN python3 -m pip install qmk appdirs --break-system-packages

# Set working directory
WORKDIR /qmk

# Copy QMK firmware (will be mounted as volume)
# Copy custom keymap (will be mounted as volume)
