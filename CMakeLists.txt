cmake_minimum_required(VERSION 3.18)
project(pacset VERSION 1.4.0 LANGUAGES C)

# Set up specifications for the C compiler.
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Set output directories.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Gather the files.
FILE(GLOB SOURCES src/*.c)
include_directories(${CMAKE_SOURCE_DIR}/headers)

# Output the project.
add_library(pacset SHARED ${SOURCES})
install(TARGETS pacset DESTINATION lib)
