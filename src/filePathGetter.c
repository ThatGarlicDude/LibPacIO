#include <stdio.h>
#include "filePathArray.h"

// Gets a filePath in the filePathArray.
const char* getFilePath(FilePathArray* filePathArray, int index) {
	return filePathArray->filePaths[index];
}

// Getter for a FilePathArray's filePaths.
const char** getFilePaths(FilePathArray* filePathArray) {
	return filePathArray->filePaths;
}

// Getter for a FilePathArray's size.
size_t* getSize(FilePathArray* filePathArray) {
	return &(filePathArray->size);
}
