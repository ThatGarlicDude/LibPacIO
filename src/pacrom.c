#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// A struct that represents a ROM file within the Pac-Man ROM set.
typedef struct pac_rom {
	char* name;			// The filename of the ROM.
	size_t size;		// The size of the ROM.
	uint8_t* data;		// The ROM's data.
} pac_rom_t;

// Initiates a new ROM.
int pac_rom_init(pac_rom_t* rom, const char* name) {
	// Stop if the ROM is null.
	if (!rom) {
		printf("Error (pac_rom_init): ROM pointer is null.\n");
		return -1;
	}
	// Allocate the filename to a safe location.
	rom->name = strdup(name);
	// Fail if the name allocation didn't work.
	if (!rom->name) {
		printf("Error (pac_rom_init): Failed to allocate ROM file name.\n");
		return -1;
	}
	// Initialize the rest of the properties.
	rom->size = 0;
	rom->data = NULL;
	return 0;
}

// Creates a new ROM.
pac_rom_t* pac_rom_create(const char* name) {
	pac_rom_t* rom = malloc(sizeof(pac_rom_t));
	// Stop if the ROM is null.
	if (!rom) {
		printf("Error (pac_rom_create): ROM pointer is null.\n");
		free(rom);
		return NULL;
	}
	// Fail if the initiation didn't work.
	if (pac_rom_init(rom, name) != 0) {
		printf("Error (pac_rom_create): Failed to initiate ROM.\n");
		free(rom);
		return NULL;
	}
	// Return the ROM.
	return rom;
}

// Clear the ROM.
int pac_rom_clear(pac_rom_t* rom) {
	// Stop if the ROM is null.
	if (!rom) {
		printf("Error (pac_rom_clear): ROM pointer is null.\n");
		return -1;
	}
	// Free everything up.
	free(rom->name);
	free(rom->data);
	// Nullify the properties.
	rom->name = NULL;
	rom->data = NULL;
	rom->size = 0;
	return 0;
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
}

// Sets the filename of a ROM.
void pac_rom_set_name(pac_rom_t* rom, const char* name) {
	// Stop if the source ROM is null.
	if (!rom) {
		printf("Error (pac_rom_set_name): ROM pointer is null.\n");
		return;
	}
	// Replace the filename.
	free(rom->name);
	rom->name = strdup(name);
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

