#include <stdio.h>

#ifndef ROM_FILE_H
#define ROM_FILE_H

	// A struct that represents a ROM in a ROM set.
	typedef struct {
		size_t size;
		const char* fileName;
		unsigned char* data;
	} RomFile;

	// Initiates a new ROM file.
	RomFile newROMFile(const char* fileName);

	// Returns a ROM file's size.
	size_t getSize(RomFile* romFile);

	// Returns a ROM file's filename.
	const char* getFileName(RomFile* romFile);

	// Returns a ROM file's data.
	unsigned char* getData(RomFile* romFile);

#endif
