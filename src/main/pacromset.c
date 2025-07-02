#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "main/pacrom.h"
#include "main/pacromset.h"
#include "main/print.h"

/*
	## MEMORY FUNCTIONS ##
*/

// Sets up a PacROMSet struct.
void pac_romset_init(pac_romset_t* romset, const char* path) {
	romset->path = strdup(path);
	romset->size = 0;
	romset->roms = NULL;
	return;
}

// Creates a new PacROMSet into memory.
pac_romset_t* pac_romset_create(const char* path) {
	pac_romset_t* romset = (pac_romset_t*) malloc(sizeof(pac_romset_t));
	if (!romset) return NULL;
	pac_romset_init(romset, path);
	return romset;
}

// Clears a PacROMSet with zeroes.
void pac_romset_clear(pac_romset_t* romset) {
	if (!romset) return;
	// Clean the path of the PacDir.
	if (romset->path) {
		memset(romset->path, 0, strlen(romset->path));
		free(romset->path);
	}
	memset(romset, 0, sizeof(pac_romset_t));
	return;
}

// Destroys a PacROMSet from memory.
void pac_romset_destroy(pac_romset_t* romset) {
	if (!romset) return;
	pac_romset_clear(romset);
	free(romset);
	return;
}

/*
	## DIRECTORY FUNCTIONS ##
*/

// Creates a new PacROMSet, and opens the directory relating to it, getting all of its filenames inside of it.
pac_romset_t* pac_romset_open(const char* path) {
	// Declare these variables.
	pac_romset_t* romset = pac_romset_create(path);
	DIR* directory = opendir(path);
	struct dirent* entry;
	// Stop if the directory doesn't exist.
	if (!romset || !directory) {
		free(romset);
		closedir(directory);
		return NULL;
	}
	romset->roms = malloc(0);
	// Go through each file in the directory.
	while ((entry = readdir(directory))) {
		// Ignore referring to itself and its parent directory.
		if (entry->d_name[0] == '.') continue;
		pac_romset_append_rom(romset, entry->d_name);
	}
	// Sort the ROM names.
	pac_romset_sort(romset);
	// Success!
	closedir(directory);
	return romset;
}

// Clears and frees everything regarding a PacROMSet from memory.
void pac_romset_close(pac_romset_t* romset) {
	if (!romset) return;
	for (size_t index; index < romset->size; index++) {
		memset(romset->roms[index], 0, strlen(romset->roms[index]));
		free(romset->roms[index]);
	}
	free(romset->roms);
	pac_romset_destroy(romset);
	return;
}

/*
	## FILE FUNCTIONS ##
*/

// Loads a PacROM using an index for a PacROMSet's ROMs array.
pac_rom_t* pac_romset_load_rom(const pac_romset_t* romset, const size_t index) {
	char* file_path = pac_romset_concat(romset, index);
	pac_rom_t* rom = pac_rom_load(file_path);
	free(file_path);
	return rom;
}

// Loads a PacROM using a file name in a PacROMSet.
pac_rom_t* pac_romset_load_rom_by_name(const pac_romset_t* romset, const char* name) {
	// TODO: Probably come back and rework on this function.
	const size_t index = pac_romset_find_rom(romset, name);
	if (index == -1) return NULL;
	return pac_romset_load_rom(romset, index);
}

/*
	## SETTER FUNCTIONS ##
*/

// Sets a pointer in a ROM name in a PacROMSet.
void pac_romset_set_rom(pac_romset_t* romset, const size_t index, char* pointer) {
	char** roms = pac_romset_get_roms(romset);
	size_t size = pac_romset_get_size(romset);
	if (index < size) roms[index] = pointer;
	return;
}

/*
	## GETTER FUNCTIONS ##
*/

// Returns the path of a PacROMSet.
char* pac_romset_get_path(const pac_romset_t* romset) {
	return romset ? romset->path : NULL;
}

// Returns the size of a PacROMSet.
size_t pac_romset_get_size(const pac_romset_t* romset) {
	return romset ? romset->size : 0;
}

// Returns the ROMs array in a PacROMSet.
char** pac_romset_get_roms(const pac_romset_t* romset) {
	return romset ? romset->roms : NULL;
}

// Gets a specific ROM name in the ROMs array in a PacROMSet.
char* pac_romset_get_rom(const pac_romset_t* romset, const size_t index) {
	char** roms = pac_romset_get_roms(romset);
	size_t size = pac_romset_get_size(romset);
	if (!roms) return NULL;
	// Safely get a ROM name within the bounds, otherwise return NULL.
	if (index < size) {
		return roms[index];
	} else {
		return NULL;
	}
}

// Gets the address of a specific ROM name in a PacROMSet.
char** pac_romset_get_rom_address(const pac_romset_t* romset, const size_t index) {
	return &romset->roms[index];
}

// Searches for a specific ROM name in a PacROMSet.
size_t pac_romset_find_rom(const pac_romset_t* romset, const char* name) {
	size_t size = pac_romset_get_size(romset);
	for (size_t index = 0; index < size; index++) {
		char* rom = pac_romset_get_rom(romset, index);
		if (strcmp(rom, name) == 0) return index;
	}
	return -1;
}

/*
	## SORT FUNCTIONS ##
*/

// Sorts all of the ROMs in a PacROMSet in lexicographic order.
void pac_romset_sort(pac_romset_t* romset) {
	for (size_t index = 0; index < romset->size; index++) {
		size_t lowest_rom = pac_romset_find_lowest_rom(romset, index);
		pac_romset_swap_roms(romset, index, lowest_rom);
	}
	return;
}

// Swaps two ROM names in a PacROMSet.
void pac_romset_swap_roms(pac_romset_t* romset, const size_t index_a, const size_t index_b) {
	char* rom_a = pac_romset_get_rom(romset, index_a);
	char* rom_b = pac_romset_get_rom(romset, index_b);
	pac_romset_set_rom(romset, index_a, rom_b);
	pac_romset_set_rom(romset, index_b, rom_a);
	return;
}

// Searches for the lowest ASCII ROM name in a PacROMSet.
size_t pac_romset_find_lowest_rom(const pac_romset_t* romset, size_t offset) {
	size_t lowest_rom = offset;
	while (pac_romset_get_rom(romset, offset)) {
		char* rom_a = pac_romset_get_rom(romset, offset);
		char* rom_b = pac_romset_get_rom(romset, lowest_rom);
		if ((strcmp(rom_a, rom_b) < 0)) lowest_rom = offset;
		offset++;
	}
	return lowest_rom;
}

/*
	## MISC FUNCTIONS ##
*/

// Appends a ROM name into a PacROMSet's stack.
void pac_romset_append_rom(pac_romset_t* romset, const char* rom_name) {
	if (!romset) return;
	romset->size++;
	romset->roms = (char**) realloc(romset->roms, sizeof(char*) * romset->size);
	romset->roms[romset->size - 1] = strdup(rom_name);
	return;
}

// Concats a PacROMSet's path and a ROM's name together.
char* pac_romset_concat(const pac_romset_t* romset, size_t index) {
	if (!romset) return NULL;
	size_t romset_path_length = strlen(romset->path);
	size_t rom_name_length = strlen(romset->roms[index]);
	size_t concatted_length = romset_path_length + rom_name_length + 2; // Make room for the '/' in between, and the null terminator at the end.
	char* concatted_path = malloc(concatted_length);
	snprintf(concatted_path, concatted_length, "%s/%s", romset->path, romset->roms[index]);
	return concatted_path;
}
