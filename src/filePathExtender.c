#include <stdio.h>
#include <stdlib.h>
#include "filePathArray.h"

// Changes the size of a FilePathArray.
void changeSize(FilePathArray* filePathArray, int size) {
	filePathArray->size = size;
	filePathArray->filePaths = (const char*) realloc(filePathArray->filePaths, sizeof(const char*) * size);
}

// Adds a filepath in the FilePathArray.
void addFilePath(FilePathArray* filePathArray, const char* filePath, int index) {
	
}

// Removes a filepath in the FilePathArray.
void removeFilePath(FilePathArray* filePathArray, int index) {
	
}

// Pushes a filePath at the start of the array.
void pushFilePath(FilePathArray* filePathArray, const char* filePath) {
	// I might have to come back to this one later.
}

// Takes the first filepath out of the array.
void popFilePath(FilePathArray* filePathArray) {
	// Same thing.
}
