#include "romFile.h"
#include "romSet.h"

#ifndef ROM_SET_PRINTER_H
#define ROM_SET_PRINTER_H

	// Prints the entire ROM data.
	void printROMData(RomFile* romFile);

	// Prints information about a ROM file.
	void printROMFile(RomFile* romFile);

	// Prints the entire data of a ROM set.
	void printROMSet(RomSet* romSet);

#endif
