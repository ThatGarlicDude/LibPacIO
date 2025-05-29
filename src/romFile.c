#include <stdio.h>
#include <stdlib.h>

// A struct that represents a ROM in a ROM set.
typedef struct {
	size_t size;
	const char* fileName;
	unsigned char* data;
} RomFile;

// Initiates a new ROM file.
RomFile newROMFile(const char* fileName) {
	printf("Initializing %s...\n", fileName);
	RomFile romFile;
	romFile.fileName = fileName;
	romFile.size = 0;
	romFile.data = NULL;
	return romFile;
}

// Returns a ROM file's size.
size_t getSize(RomFile* romFile) {
	return romFile->size;
}

// Returns a ROM file's filename.
const char* getFileName(RomFile* romFile) {
	return romFile->fileName;
}

// Returns a ROM file's data.
unsigned char* getData(RomFile* romFile) {
	return romFile->data;
}
