#include <stdio.h>
#include "filePathArray.h"

// Finds the leftmost index that refers to a null pointer.
int findFirstNull(FilePathArray* filePathArray) {
	size_t size = filePathArray->size;
	for (int index = 0; index < size; index++) {
		printf("Pointer for index %d is %p.\n", index, &(filePathArray->filePaths[index]));
		if (filePathArray->filePaths[index] == NULL) {
			return index;
		}
	}
	return -1; // Return a negative number if no nulls are found.
}

// Ditto, but for the rightmost.
int findLastNull(FilePathArray* filePathArray) {
	size_t size = filePathArray->size;
	for (int index = size - 1; index >= 0; index--) {
		if (filePathArray->filePaths[index] == NULL) {
			return index;
		}
	}
	return -1;
}
