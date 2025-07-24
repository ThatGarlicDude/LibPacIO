cmake_minimum_required(VERSION 3.18)
project(pacio VERSION 3.2.1 LANGUAGES C)
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
	DIRECTORY include/				# Get everything from the include directory in the library...
	DESTINATION include				# ...and put them to the system's local include directory.
	FILES_MATCHING
	PATTERN "*.h"					# Look for headers in the library.
	PATTERN ".git" EXCLUDE			# Ignore .git files.
	PATTERN ".DS_Store" EXCLUDE		# Ignore the annoying .DS_Store files.
	PATTERN ".swp" EXCLUDE			# Also ignore the annoying .swp files.
	PATTERN "test" EXCLUDE			# We don't need to include the test directory.
)
install(TARGETS pacio DESTINATION lib)

# Output the test executable.
add_executable(pacio_test ${TEST_FILES})
target_include_directories(pacio_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/test)
target_link_libraries(pacio_test PRIVATE pacio)
install(TARGETS pacio_test DESTINATION bin)
