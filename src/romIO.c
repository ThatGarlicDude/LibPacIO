#include <stdio.h>
#include <stdlib.h>
#include "romFile.h"

// Extracts the data from a ROM file into virtual ROM.
int readROM(RomFile* romFile) {
	FILE* file = fopen(romFile->fileName, "rb");
	// Does the file exist?
	if (file == NULL) {
		printf("Failed to open ROM file.\n");
		return -1;
	}
	// Can it seek to the end of the file?
	if (fseek(file, 0, SEEK_END) == 0) {
		romFile->size = ftell(file);
		rewind(file);
	} else {
		printf("Failed to seek the end of ROM file: %s.\n", romFile->fileName);
		return -1;
	}
	// Extract each of the ROM's bytes to the RomFile's data.
	romFile->data = (unsigned char*) malloc(romFile->size);
	for (long index = 0; index < romFile->size; index++) {
		romFile->data[index] = fgetc(file);
	}
	// Close the file.
	fclose(file);
	return 0;
}

// Overwrites a ROM file using a virtual ROM's data.
int writeROM(RomFile* romFile, char* data) {
	FILE* file = fopen(romFile->fileName, "wb");
	// Does the file exist?
	if (file == NULL) {
		printf("Failed to open ROM file.\n");
		return -1;
	}
	// Write the ROM file.
	fputs(data, file);
	// Close the file.
	fclose(file);
	return 0;
}

// Clears out a ROM file's data.
int freeROMData(RomFile* romFile) {
	// Fail if the data is already empty.
	if (romFile->data == NULL) {
		printf("ROM file %s's data has already been freed.", romFile->fileName);
		return -1;
	}
	// Free the data.
	free(romFile->data);
	romFile->size = 0;
	return 0;
}
