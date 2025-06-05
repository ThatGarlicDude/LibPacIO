#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "pacrom.h"
#include "pacio.h"

// The pre-made size for pac_rom_t.
const size_t PAC_ROM_SIZE = sizeof(pac_rom_t);

// Initiates a new ROM.
void pac_rom_init(pac_rom_t* rom, const char* name) {
	// Stop if the ROM is null.
	if (!rom) {
		printf("Error (pac_rom_init): ROM pointer is null.\n");
		return;
	}
	// Safely copy the name to the ROM's name.
	strncpy(rom->name, name, PAC_NAME_MAX);
	rom->name[PAC_NAME_MAX] = '\0';
	return;
}

// Creates a new ROM.
pac_rom_t* pac_rom_create(const char* name) {
	// Allocate the ROM.
	pac_rom_t* rom = calloc(1, sizeof(pac_rom_t));
	// Stop if the ROM is null.
	if (!rom) {
		printf("Error (pac_rom_create): ROM pointer is null.\n");
		free(rom);
		return NULL;
	}
	// Initialize the ROM.
	pac_rom_init(rom, name);
	// Return the ROM.
	return rom;
}

// Clear the ROM.
void pac_rom_clear(pac_rom_t* rom) {
	// Stop if the ROM is null.
	if (!rom) {
		printf("Error (pac_rom_clear): ROM pointer is null.\n");
		return;
	}
	// If possible, unload the ROM's data if there is any.
	pac_rom_unload(rom);
	free(rom->data);
	// Clean the ROM set.
	memset(rom, 0, sizeof(pac_rom_t));
	return;
}

// Destroy the ROM.
void pac_rom_destroy(pac_rom_t* rom) {
	// Stop if the ROM is null.
	if (!rom) {
		printf("Error (pac_rom_destroy): ROM pointer is null.\n");
		return;
	}
	// Clear and free the ROM.
	pac_rom_clear(rom);
	free(rom);
	return;
}

// Copies a ROM source to a destination.
void pac_rom_copy(const pac_rom_t* rom_source, pac_rom_t* rom_destination) {
	// Stop if either of the pointers are null.
	if (!rom_source || !rom_destination) {
		return;
	}
	// Go through each of the struct's bytes.
	for (size_t index = 0; index < PAC_ROM_SIZE; index++) {
		rom_destination[index] = rom_source[index];
	}
	return;
}

// Duplicates a ROM to a destination.
pac_rom_t* pac_rom_duplicate(const pac_rom_t* rom_source) {
	pac_rom_t* rom_destination;
	// Stop if the ROM pointer is null.
	if (!rom_source) {
		return NULL;
	}
	// Create the new ROM destination.
	rom_destination = pac_rom_create(rom_source->name);
	// If it exists...
	if (rom_destination) {
		// Copy bytes from source to the destination.
		pac_rom_copy(rom_source, rom_destination);
		return rom_destination;
	} else {
		// Otherwise, free the ROM.
		free(rom_destination);
		return NULL;
	}
}

// Returns a ROM's filename.
const char* pac_rom_get_name(const pac_rom_t* rom) {
	return rom ? rom->name : NULL;
}

// Returns a ROM's size.
size_t pac_rom_get_size(const pac_rom_t* rom) {
	return rom ? rom->size : 0;
}

// Returns a ROM's data.
const uint8_t* pac_rom_get_data(const pac_rom_t* rom) {
	return rom ? rom->data : NULL;
}

