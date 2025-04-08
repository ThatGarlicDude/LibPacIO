/*
When it comes to creating strings in a dynamic array, they're always made to be
null from the start. That means there's nothing pointing in regards to those
strings. This is a problem because we need valid data getting pointed at the
very least. This is where the stringAdder comes to play. Without it, we would
just have an array having pointers that don't actually point to anything, not
even strings at all.
*/

#include <stdio.h>
#include "filePathArray.h"

// Gives a filePath a new string.
void addString(FilePathArray* filePathArray, int index, const char* STRING) {
	// Replace the null string with the default one.
	if (STRING == NULL) {
		return;
	}
	filePathArray->filePaths[index] = STRING;
}

// Sets all the filePaths in the array their strings.
void addStrings(FilePathArray* filePathArray, const char* STRING) {
	size_t size = filePathArray->size;
	for (int index; index < size; index++) {
		addString(filePathArray, index, STRING);
	}
}
