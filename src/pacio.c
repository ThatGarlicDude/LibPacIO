#include <stdio.h>
#include <dirent.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "pacrom.h"
#include "pacio.h"
#ifdef _WIN32
	#include <windows.h>
#endif

// Loads data from a ROM file.
int pac_rom_load(pac_rom_t* rom) {
	FILE* file;
	// Stop if there is no ROM pointer.
	if (!rom) {
		printf("Error (pac_rom_load): ROM pointer is null.\n");
		return -1;
	}
	// Open the file in read mode.
	file = fopen(rom->name, "rb");
	// Does the file exist?
	if (!file) {
		printf("Error (pac_rom_load): File pointer is null.\n");
		fclose(file);
		return -1;
	}
	// Can it seek to the end of the file?
	if (fseek(file, 0, SEEK_END) == 0) {
		rom->size = ftell(file);
		rewind(file);
	} else {
		printf("Error (pac_rom_load): Failed to seek the end of ROM file: %s.\n", rom->name);
		fclose(file);
		return -1;
	}
	// Extract each of the ROM's bytes to the RomFile's data.
	rom->data = (uint8_t*) malloc(rom->size);
	// Fail if the allocation didn't work.
	if (!rom->data) {
		printf("Error (pac_rom_load): Failed to allocate ROM data.\n");
		free(rom->data);
		fclose(file);
		return -1;
	}
	for (size_t index = 0; index < rom->size; index++) {
		rom->data[index] = fgetc(file);
	}
	// Close the file.
	fclose(file);
	return 0;
}

// Unloads extracted ROM data from memory.
int pac_rom_unload(pac_rom_t* rom) {
	// Stop if there is no ROM pointer.
	if (!rom) {
		printf("Error (pac_rom_unload): ROM pointer is null.\n");
		return -1;
	}
	if (!rom->data) {
		//printf("Error (pac_rom_unload): ROM data pointer is null.\n");
		return -1;
	}
	// Clear the ROM data.
	memset(rom->data, 0, rom->size);
	free(rom->data);
	return 0;
}

// Saves data to a ROM file.
int pac_rom_save(const pac_rom_t* rom) {
	FILE* file;
	// Stop if there is no ROM pointer.
	if (!rom) {
		printf("Error (pac_rom_save): ROM pointer is null.\n");
		return -1;
	}
	file = fopen(rom->name, "wb");
	// Does the file exist?
	if (file == NULL) {
		printf("Error (pac_rom_save): File pointer is null.\n");
		fclose(file);
		return -1;
	}
	// Write the ROM file.
	fputs(rom->data, file);
	// Close the file.
	fclose(file);
	return 0;
}

// Generates the absolute path.
char* pac_path_generate(const char* path) {
	// Stop if there is no specifed path.
	if (!path) {
		return NULL;
	}
	// Use Windows-only code if the user is compiling on Windows.
	#ifdef _WIN32
		char absolute_path* = malloc(MAX_PATH);
		if (!absolute_path) {
			free(absolute_path);
			return NULL;
		}
		DWORD length = GetFullPathNameA(path, MAX_PATH, absolute_path, NULL);
		if (length == 0 || length >= MAX_PATH) {
			free(absolute_path);
			return NULL;
		}
		return absolute_path;
	#else
		return realpath(path, NULL);
	#endif
}

// Cleans out the absolute path.
void pac_path_clear(char* path) {
	// Stop if there's no path.
	if (!path) {
		return;
	}
	// Clean the whole absolute path.
	memset(path, 0, strlen(path) + 1);
	free(path);
}
