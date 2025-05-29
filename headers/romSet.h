#include <stdio.h>
#include "romFile.h"

#ifndef ROM_SET_H
#define ROM_SET_H

	// A dynamic array that contains the ROM filepaths.
	typedef struct {
		size_t size;
		RomFile* roms;
	} RomSet;

	// Initializes a new ROM set.
	RomSet newROMSet();

	// Returns the address of a ROM file.
	RomFile* getROM(RomSet* romSet, int index);

	// Frees the dynamic array inside the ROM set.
	int freeROMs(RomSet* romSet);

#endif
