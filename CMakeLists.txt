cmake_minimum_required(VERSION 3.12) # Cmake must be on version 3.12 or above to proceed.
project(pacset VERSION 1.0.0) # Start the project.

set(CMAKE_C_STANDARD 99) # C99 is required.
set(CMAKE_C_STANDARD_REQUIRED ON)

FILE(GLOB SOURCES src/*.c) # Get all the files from the src directory.

add_library(pacset SHARED ${SOURCES}) # Create the library.

install(TARGETS pacset DESTINATION /usr/local/lib) # Put the library in the lib folder.

target_include_directories(pacset PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers) # Get the files in the header directory as well.
