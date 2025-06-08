#include <stdio.h>
#include <dirent.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "pacrom.h"
#include "pacio.h"
#include "paclimits.h"
#include "pacerror.h"
#ifdef _WIN32
	#include <windows.h>
#endif

const char* NAME_PAC_ROM_LOAD = "pac_rom_load";
const char* NAME_PAC_ROM_UNLOAD = "pac_rom_unload";
const char* NAME_PAC_ROM_SAVE = "pac_rom_save";
const char* NAME_PAC_PATH_GENERATE = "pac_path_generate";
const char* NAME_PAC_PATH_CLEAR = "pac_path_clear";

// Loads data from a ROM file.
int pac_rom_load(pac_rom_t* rom) {
	pac_info(NAME_PAC_ROM_LOAD, "Loading ROM...");
	if (!rom) {
		pac_warn(NAME_PAC_ROM_LOAD, "ROM pointer is NULL!");
		return -1;
	}
	pac_info(NAME_PAC_ROM_LOAD, "Opening file...");
	FILE* file = fopen(rom->name, "rb");
	if (!file) {
		pac_error(NAME_PAC_ROM_LOAD, "Failed to open file.");
		fclose(file);
		return -1;
	}
	pac_info(NAME_PAC_ROM_LOAD, "Getting the size of the file...");
	if (fseek(file, 0, SEEK_END) == 0) {
		rom->size = ftell(file);
		rewind(file);
	} else {
		pac_error(NAME_PAC_ROM_LOAD, "Failed to seek the file.");
		fclose(file);
		return -1;
	}
	pac_info(NAME_PAC_ROM_LOAD, "Allocating ROM data...");
	rom->data = (uint8_t*) malloc(rom->size);
	if (!rom->data) {
		pac_error(NAME_PAC_ROM_LOAD, "Failed to allocate ROM data.");
		fclose(file);
		return -1;
	}
	pac_info(NAME_PAC_ROM_LOAD, "Extracting bytes to the struct's data...");
	for (size_t index = 0; index < rom->size; index++) {
		rom->data[index] = fgetc(file);
	}
	pac_info(NAME_PAC_ROM_LOAD, "Successfully loaded ROM!");
	fclose(file);
	return 0;
}

// Unloads extracted ROM data from memory.
int pac_rom_unload(pac_rom_t* rom) {
	pac_info(NAME_PAC_ROM_UNLOAD, "Unloading ROM...");
	if (!rom) {
		pac_warn(NAME_PAC_ROM_UNLOAD, "ROM pointer is NULL!");
		return -1;
	}
	if (!rom->data) {
		pac_warn(NAME_PAC_ROM_UNLOAD, "ROM data pointer is NULL!");
		return -1;
	}
	pac_info(NAME_PAC_ROM_UNLOAD, "Clearing and freeing ROM data...");
	memset(rom->data, 0, rom->size);
	free(rom->data);
	pac_info(NAME_PAC_ROM_UNLOAD, "Successfully unloaded ROM!");
	return 0;
}

// Saves data to a ROM file.
int pac_rom_save(const pac_rom_t* rom) {
	pac_info(NAME_PAC_ROM_SAVE, "Saving ROM...");
	if (!rom) {
		pac_warn(NAME_PAC_ROM_SAVE, "ROM pointer is NULL!");
		return -1;
	}
	pac_info(NAME_PAC_ROM_SAVE, "Opening file...");
	FILE* file = fopen(rom->name, "wb");
	if (!file) {
		pac_error(NAME_PAC_ROM_SAVE, "Failed to open file.");
		fclose(file);
		return -1;
	}
	pac_info(NAME_PAC_ROM_SAVE, "Overwriting data to the ROM file...");
	fputs(rom->data, file);
	pac_info(NAME_PAC_ROM_SAVE, "Successfully saved ROM!");
	fclose(file);
	return 0;
}

// Generates the absolute path.
char* pac_path_generate(const char* path) {
	pac_info(NAME_PAC_PATH_GENERATE, "Generating absolute path...");
	if (!path) {
		pac_warn(NAME_PAC_PATH_GENERATE, "Path pointer is NULL!");
		return NULL;
	}
	// Use Windows-only code if the user is compiling on Windows.
	#ifdef _WIN32
		pac_info(NAME_PAC_PATH_GENERATE, "Windows detected! Allocating absolute path...");
		char absolute_path* = malloc(MAX_PATH);
		if (!absolute_path) {
			pac_error(NAME_PAC_PATH_GENERATE, "Failed to allocate absolute path.");
			return NULL;
		}
		pac_info(NAME_PAC_PATH_GENERATE, "Getting full path name...");
		DWORD length = GetFullPathNameA(path, MAX_PATH, absolute_path, NULL);
		if (length == 0 || length >= MAX_PATH) {
			pac_error(NAME_PAC_PATH_GENERATE, "Failed to get full path name.");
			free(absolute_path);
			return NULL;
		}
		pac_info(NAME_PAC_PATH_GENERATE, "Successfully generated absolute path!");
		return absolute_path;
	#else
		pac_info(NAME_PAC_PATH_GENERATE, "Linux/MacOS detected! Using realpath...");
		return realpath(path, NULL);
	#endif
}

// Cleans out the absolute path.
void pac_path_clear(char* path) {
	pac_info(NAME_PAC_PATH_CLEAR, "Clearing absolute path...");
	if (!path) {
		pac_warn(NAME_PAC_PATH_CLEAR, "Path pointer is NULL!");
		return;
	}
	pac_info(NAME_PAC_PATH_CLEAR, "Cleaning the absolute path with zeroes...");
	memset(path, 0, strlen(path) + 1);
	free(path);
	pac_info(NAME_PAC_PATH_CLEAR, "Successfully cleared the absolute path!");
	return;
}
