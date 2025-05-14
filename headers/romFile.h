#include <stdio.h>

#ifndef ROM_FILE_H
#define ROM_FILE_H

	// A struct that represents a ROM in a ROM set.
	typedef struct {
		char* fileName;
	} RomFile;

	// Initiates a new ROM file.
	RomFile newROMFile(char* fileName);

	// Returns a ROM file's filename.
	char* getFileName(RomFile* romFile);

	// Reads the whole ROM file, and returns its data.
	void readROMFile(RomFile* romFile);

	// Writes content into a ROM file.
	void writeROMFile(RomFile* romFile);

#endif
