#include <stdio.h>

#ifndef ROM_SET_H
#define ROM_SET_H

	// A dynamic array that contains the ROM filepaths.
	typedef struct {
		size_t size;
		const char** filePaths;
	} RomSet;

	// Initializes a new ROM set.
	RomSet newRomSet();

	// Frees the dynamic array inside the ROM set.
	void freeFilePaths(RomSet* romSet);

#endif
