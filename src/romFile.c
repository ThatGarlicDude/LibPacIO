#include <stdio.h>

// A struct that represents a ROM in a ROM set.
typedef struct {
	char* fileName;
} RomFile;

// Initiates a new ROM file.
RomFile newROMFile(char* fileName) {
	RomFile romFile;
	romFile.fileName = fileName;
	return romFile;
}

// Returns a ROM file's filename.
char* getFileName(RomFile* romFile) {
	return romFile->fileName;
}

// Reads the whole ROM file, and returns its data.
void readROMFile(RomFile* romFile) {
	return;
}

// Writes content into a ROM file.
void writeROMFile(RomFile* romFile) {
	return;
}
