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

	// Frees the dynamic array inside the ROM set.
	void freeROMs(RomSet* romSet);

#endif
