#include <stdio.h>
#include <stdlib.h>
#include "romSet.h"
#include "romSet.h"

// Changes the array size of a ROM set.
void changeRomSetSize(RomSet* romSet, size_t size) {
	romSet->size = size;
	romSet->roms = realloc(romSet->roms, sizeof(const char*) * size);
}

// Appends a ROM into a ROM set.
void appendRom(RomSet* romSet, char* romName) {
	size_t temporarySize = romSet->size;
	RomFile romFile = newROMFile(romName);
	changeRomSetSize(romSet, temporarySize + 1);
	romSet->roms[temporarySize] = romFile;
}
