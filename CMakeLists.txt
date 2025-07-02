cmake_minimum_required(VERSION 3.18)
project(pacio VERSION 3.1.0 LANGUAGES C)
project(pacio_test LANGUAGES C)

# Set up specifications for the C compiler.
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Set output directories.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Gather the files.
FILE(GLOB MAIN_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main/*.c)
FILE(GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/test/*.c)

# Output the library.
add_library(pacio SHARED ${MAIN_FILES})
target_include_directories(pacio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
install(
	DIRECTORY include/main
	DESTINATION /usr/local/include/libpacio
	FILES_MATCHING PATTERN "*.h"
	PATTERN ".git" EXCLUDE
	PATTERN ".DS_Store" EXCLUDE
)
install(TARGETS pacio DESTINATION lib)

# Output the test executable.
add_executable(pacio_test ${TEST_FILES})
target_include_directories(pacio_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(pacio_test PRIVATE pacio)
install(TARGETS pacio_test DESTINATION bin)
