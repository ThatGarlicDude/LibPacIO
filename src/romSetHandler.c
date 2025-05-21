#include <stdio.h>
#include <stdlib.h>
#include "romSet.h"
#include "romFile.h"

// Changes the array size of a ROM set.
void changeROMSetSize(RomSet* romSet, size_t size) {
	romSet->size = size;
	romSet->roms = realloc(romSet->roms, sizeof(RomFile) * size);
}

// Appends a ROM into a ROM set.
void appendROM(RomSet* romSet, char* romName) {
	size_t temporarySize = romSet->size;
	RomFile romFile = newROMFile(romName);
	changeROMSetSize(romSet, temporarySize + 1);
	romSet->roms[temporarySize] = romFile;
}
