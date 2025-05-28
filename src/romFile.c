#include <stdio.h>

// A struct that represents a ROM in a ROM set.
typedef struct {
	size_t size;
	char* fileName;
	unsigned char* data;
} RomFile;

// Initiates a new ROM file.
RomFile newROMFile(char* fileName) {
	RomFile romFile;
	romFile.fileName = fileName;
	romFile.size = 0;
	return romFile;
}

// Returns a ROM file's size.
size_t getSize(RomFile* romFile) {
	return romFile->size;
}

// Returns a ROM file's filename.
char* getFileName(RomFile* romFile) {
	return romFile->fileName;
}

// Returns a ROM file's data.
unsigned char* getData(RomFile* romFile) {
	return romFile->data;
}
