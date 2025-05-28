#include <stdio.h>
#include "romFile.h"

#ifndef ROM_IO_H
#define ROM_IO_H

	// Extracts the data from a ROM file into a virtual ROM.
	int readROM(RomFile* romFile);

	// Overwrites a ROM file using a virtual ROM's data.
	int writeROM(RomFile* romFile, char* data);

	// Clears out a ROM file's data.
	int freeROMData(RomFile* romFile);

#endif
