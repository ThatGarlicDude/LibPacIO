#include <stdio.h>
#include "filePathArray.h"

/*
Not really an important function in the library, but it's useful for
debugging. Sometimes, strings are difficult to manage, especially with
arrays. That's why these printing functions exist.
*/
void printFilePath(FilePathArray* filePathArray, int index) {
	const char* filePath = filePathArray->filePaths[index];
	// Check to see if the string is null. Otherwise, don't proceed.
	if (filePath == NULL) {
		printf("NULL\n"); // Just print this instead.
		return;
	}
	printf("%s\n", filePath);
}

// Prints all filesnames in a FilePathArray.
void printAllFilePaths(FilePathArray* filePathArray) {
	// Go through each of the filePaths in the array.
	for (int index = 0; index < filePathArray->size; index++) {
		printFilePath(filePathArray, index);
	}
}

// Prints a filePath's pointer. Used for debugging purposes.
void printFilePathPointer(FilePathArray* filePathArray, int index) {
	const char* filePath = (const char*) filePathArray->filePaths[index];
	printf("%p\n", filePath);
}

// Prints all the pointers.
void printAllFilePathPointers(FilePathArray* filePathArray) {
	for (int index = 0; index < filePathArray->size; index++) {
		printFilePathPointer(filePathArray, index);
	}
}
