#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "pacrom.h"
#include "pacio.h"

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

