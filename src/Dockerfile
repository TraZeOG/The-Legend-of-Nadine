FROM ubuntu:22.04

# Updates packages, install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libsdl2-dev \
    libsdl2-mixer-dev \
    && rm -rf /var/lib/apt/lists/*

# Define workdir
WORKDIR /app

# Copy everything in a container
COPY . .

# Compile
RUN make

# Execute project
CMD ["./game"]