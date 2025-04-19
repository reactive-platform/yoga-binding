# Use a base image with ARM64 support
FROM debian:bullseye-slim AS build-env

# Install necessary dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    ninja-build \
    cmake \
    mingw-w64 \
    git \
    python3 \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Set up environment variables for the cross-compiler
ENV CC=x86_64-w64-mingw32-gcc
ENV CXX=x86_64-w64-mingw32-g++
ENV AR=x86_64-w64-mingw32-ar
ENV RANLIB=x86_64-w64-mingw32-ranlib

# Create a working directory
WORKDIR /project

# Copy project files into the container
COPY . .

# Build the project
RUN mkdir bin \
    && cmake -G Ninja -B bin \
       -DCMAKE_SYSTEM_NAME=Windows \
       -DCMAKE_SYSTEM_PROCESSOR=x86_64 \
       -DCMAKE_C_COMPILER=${CC} \
       -DCMAKE_CXX_COMPILER=${CXX} \
    && cmake --build bin

# Create the runtime image
FROM debian:bullseye-slim AS runtime-env

# Install necessary libraries (if required)
RUN apt-get update && apt-get install -y --no-install-recommends \
    wine \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Copy the build artifacts
WORKDIR /app
COPY --from=build-env /project/bin /app/bin

# Default command to list the compiled files
CMD ["ls", "-la", "/app/bin"]
