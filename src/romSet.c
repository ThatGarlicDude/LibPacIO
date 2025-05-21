#include <stdio.h>
#include <stdlib.h>
#include "romFile.h"

// A dynamic array that contains the ROM filepaths.
typedef struct {
	size_t size;
	RomFile* roms;
} RomSet;

// Initializes a new ROM set.
RomSet newROMSet() {
	RomSet romSet;
	romSet.size = 0;
	romSet.roms = malloc(0);
	return romSet;
}

// Returns the address of a ROM file.
RomFile* getROM(RomSet* romSet, int index) {
	return &(romSet->roms[index]);
}

// Frees the dynamic array inside the ROM set.
void freeROMs(RomSet* romSet) {
	free(romSet->roms);
	romSet->size = 0;
}
