cmake_minimum_required(VERSION 3.18)
project(pacset VERSION 2.2.0 LANGUAGES C CXX)

# Set up specifications for the C compiler.
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Set output directories.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Gather the files.
FILE(GLOB MAIN
	${CMAKE_CURRENT_SOURCE_DIR}/src/test.c
)
FILE(GLOB SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/pacio.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/pacprint.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/pacrom.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/pacset.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/paclimits.c
)

# Output the library.
add_library(pacset SHARED ${SOURCES})
target_include_directories(pacset PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
install(TARGETS pacset DESTINATION lib)
# Output the test executable.
add_executable(pacset_test ${MAIN})
target_link_libraries(pacset_test PRIVATE pacset)
install(TARGETS pacset_test DESTINATION bin)
