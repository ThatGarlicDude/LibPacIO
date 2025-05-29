cmake_minimum_required(VERSION 3.18)
project(pacset VERSION 1.7.1 LANGUAGES C)

# Set up specifications for the C compiler.
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Set output directories.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Gather the files.
FILE(GLOB SOURCES src/*.c)

# Output the project.
add_library(pacset SHARED ${SOURCES})
target_include_directories(pacset PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
install(TARGETS pacset DESTINATION lib)
