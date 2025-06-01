#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "pacrom.h"

// Loads data from a ROM file.
int pac_rom_load(pac_rom_t* rom) {
	FILE* file = fopen(rom->name, "rb");
	// Does the file exist?
	if (file == NULL) {
		printf("Error (pac_rom_load): File doesn't exist (it's null).\n");
		return -1;
	}
	// Can it seek to the end of the file?
	if (fseek(file, 0, SEEK_END) == 0) {
		rom->size = ftell(file);
		rewind(file);
	} else {
		printf("Error (pac_rom_load): Failed to seek the end of ROM file: %s.\n", rom->name);
		return -1;
	}
	// Extract each of the ROM's bytes to the RomFile's data.
	rom->data = (uint8_t*) malloc(rom->size);
	for (size_t index = 0; index < rom->size; index++) {
		rom->data[index] = fgetc(file);
	}
	// Close the file.
	fclose(file);
	return 0;
}

// Saves data to a ROM file.
int pac_rom_save(const pac_rom_t* rom) {
	FILE* file = fopen(rom->name, "wb");
	// Does the file exist?
	if (file == NULL) {
		printf("Error (pac_rom_save): File doesn't exist (it's null).\n");
		return -1;
	}
	// Write the ROM file.
	fputs(rom->data, file);
	// Close the file.
	fclose(file);
	return 0;
}

// Unloads extracted ROM data from memory.
int pac_rom_unload(pac_rom_t* rom) {
	FILE* file = fopen(rom->name, "wb");
	// Does the file exist?
	if (file == NULL) {
		printf("Error (pac_rom_unload): File doesn't exist (it's null).\n");
		return -1;
	}
	// Clear the ROM data.
	memset(rom->data, 0, rom->size);
	return 0;
}
