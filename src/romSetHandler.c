#include <stdio.h>
#include <stdlib.h>
#include "romSet.h"
#include "romFile.h"

// Changes the array size of a ROM set.
void changeROMSetSize(RomSet* romSet, size_t size) {
	printf("Changing the size of the ROM set to %zu...\n", size);
	romSet->size = size;
	romSet->roms = realloc(romSet->roms, sizeof(RomFile) * size);
	// Check if the ROMs array is still valid.
	if (romSet->roms == NULL) {
		printf("ROMs array got nullified.\n");
		return;
	}
}

// Appends a ROM into a ROM set.
void appendROM(RomSet* romSet, const char* romName) {
	size_t temporarySize;
	printf("Appending %s into the ROM set...\n", romName);
	// Check if the ROM set is valid.
	if (romSet == NULL) {
		printf("The ROM set is null.\n");
		return;
	}
	temporarySize = romSet->size;
	// Create the ROM file.
	RomFile romFile = newROMFile(romName);
	changeROMSetSize(romSet, temporarySize + 1);
	romSet->roms[temporarySize] = romFile;
}
