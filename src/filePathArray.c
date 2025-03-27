#include <stdio.h>
#include <stdlib.h>

/*
Most arcade games use a set of ROMs called a "ROM set" in their PCBs. When
those ROMs get extracted, they're converted into files and then put in a
directory called a "ROM set directory". That said, a ROM set directory is
just a digital version of a PCB, but it doesn't power any of its ROMs. For
instance, a ROM set directory cannot read or write their ROMs' data; they only
contain them. If we want to get the ROMs in the directory, we must use an
array that contains them. But we need to use a dyanmic array to get as much
files as we can.
*/
typedef struct {
	const char** filePaths; // Dynamic array.
	size_t size;
} FilePathArray;

// Initializes a new FilePathArray.
FilePathArray newFilePathArray(size_t size) {
	FilePathArray filePathArray;
	filePathArray.size = size;
	filePathArray.filePaths = malloc(sizeof(char*) * size);
	return filePathArray;
}

// Ditto, but it's empty from the start.
FilePathArray newEmptyFilePathArray() {
	return newFilePathArray(0);
}
