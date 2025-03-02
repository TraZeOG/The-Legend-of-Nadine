FROM ubuntu:22.04

# Updates packages, install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libsdl2-dev \
    libsdl2-mixer-dev \
    locales \
    fonts-noto-color-emoji \
    && rm -rf /var/lib/apt/lists/*

# Configure local LANG
RUN locale-gen en_US.UTF-8 \
    && update-locale LANG=en_US.UTF-8

# Define local LANG
ENV LANG=en_US.UTF-8
ENV LANGUAGE=en_US:en
ENV LC_ALL=en_US.UTF-8

# Define workdir
WORKDIR /app

# Copy everything in a container
COPY . .

# Compile
RUN make

# Execute project
CMD ["./game"]