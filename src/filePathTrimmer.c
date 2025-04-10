/*
* When a filePathArray overshoots the amount of ROMs in a ROM set directory,
* the remaining filePaths will just point to null, and we don't want any null
* pointers in an array. This is where the filePathTrimmer comes to play.
* It'll find any null pointers in a filePathArray, and get rid of them. That
* is implemented to free up space from unnecessary null padding.
*/

#include <stdio.h>
#include "filePathArray.h"
#include "filePathExtender.h"
#include "nullHandler.h"

// Trims a filePathArray using an offset and amount.
void trimFilePathArray(FilePathArray* filePathArray, int offset, int amount) {
	// Might have to come back to this one.
	return;
}

// Will look for the first null pointer, and change the size of the array, ending before the null pointer was found.
void trimFilePathArrayByFirstNull(FilePathArray* filePathArray) {
	int firstNull = findFirstNull(filePathArray);
	// If there are no null pointers, just do not trim.
	if (firstNull == -1) {
		return;
	}
	changeSize(filePathArray, firstNull);
}
