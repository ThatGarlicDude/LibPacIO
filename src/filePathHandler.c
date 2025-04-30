#include <stdio.h>
#include <stdlib.h>
#include "romSet.h"

// Changes the array size of a ROM set.
void changeRomSetSize(RomSet* romSet, size_t size) {
	romSet->size = size;
	romSet->filePaths = realloc(romSet->filePaths, sizeof(const char*) * size);
}

// Appends a ROM into a ROM set.
void appendRom(RomSet* romSet, const char* romFilePath) {
	size_t temporarySize = romSet->size;
	changeRomSetSize(romSet, temporarySize + 1);
	romSet->filePaths[temporarySize] = romFilePath;
}
