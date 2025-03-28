#include <stdio.h>
#include "filePathArray.h"

/*
I might have to come back to this one because I can't really
seem to find a use for this one. Maybe it'll someday have
purpose.
*/
// Finds the leftmost null pointer in a FilePathArray.
const char* findFirstNull(FilePathArray* filePathArray) {
	size_t size = filePathArray->size;
	for (int index = 0; index < size; index++) {
		printf("Pointer for index %d is %p.\n", index, &(filePathArray->filePaths[index]));
		if (filePathArray->filePaths[index] == NULL) {
			return &(filePathArray->filePaths[index]);
		}
	}
	return NULL; // Don't return any addresses that point to null.
}

// Ditto, but for the rightmost.
const char* findLastNull(FilePathArray* filePathArray) {
	size_t size = filePathArray->size;
	for (int index = size - 1; index >= 0; index--) {
		if (filePathArray->filePaths[index] == NULL) {
			return &(filePathArray->filePaths[index]);
		}
	}
	return NULL;
}
