#include <stdio.h>
#include <stdlib.h>

// A dynamic array that contains the ROM filepaths.
typedef struct {
	size_t size;
	const char** filePaths;
} RomSet;

// Initializes a new ROM set.
RomSet newRomSet() {
	RomSet romSet;
	romSet.size = 0;
	romSet.filePaths = malloc(0);
	return romSet;
}

// Frees the dynamic array inside the ROM set.
void freeFilePaths(RomSet* romSet) {
	free(romSet->filePaths);
	romSet->size = 0;
}
