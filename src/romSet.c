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
	printf("Initializing ROM set...\n");
	RomSet romSet;
	romSet.size = 0;
	romSet.roms = malloc(0);
	// If this fails for some reason, throw an error, but keep going.
	if (romSet.roms == NULL) {
		printf("Failed to allocate the ROMs array.\n");
	}
	return romSet;
}

// Returns the address of a ROM file.
RomFile* getROM(RomSet* romSet, int index) {
	return &(romSet->roms[index]);
}

// Frees the dynamic array inside the ROM set.
int freeROMs(RomSet* romSet) {
	printf("Freeing ROM set...\n");
	// If the ROM set has no ROMs, then just throw an error.
	if (romSet->roms == NULL) {
		printf("ROM set is already empty.\n");
		return -1;
	}
	printf("ROM set successfully cleared.\n");
	free(romSet->roms);
	romSet->size = 0;
	return 0;
}
