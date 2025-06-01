#include <stdio.h>
#include <stdlib.h>
#include "pacrom.h"

// A struct that represents a ROM set. Designed specifically for Pac-Man in mind.
typedef struct pac_set {
	size_t size;		// The amount of ROMs in the set.
	pac_rom_t** roms;	// Dynamic array containing the ROM pointers.
} pac_set_t;

// Initializes a new ROM set.
int pac_set_init(pac_set_t* set) {
	// Stop if the ROM set is null.
	if (!set) {
		printf("Error (pac_set_init): ROM set pointer is null.\n");
		return -1;
	}
	// Initialize the size.
	set->size = 0;
	// Allocate the ROMs array.
	set->roms = (pac_rom_t**) malloc(sizeof(pac_rom_t*) * 0);
	// Stop if the array allocation fails.
	if (!set->roms) {
		printf("Error (pac_set_init): Failed to allocate ROM array.\n");
		return -1;
	}
	// Success.
	return 0;
}

// Creates a new ROM set.
pac_set_t* pac_set_create() {
	// Allocate the ROM set.
	pac_set_t* set = malloc(sizeof(pac_set_t));
	// Stop if the allocation failed.
	if (!set) {
		printf("Error (pac_set_create): Failed to allocate ROM set.\n");
		return NULL;
	}
	// Return the set.
	return set;
}

// Clears the ROM set.
int pac_set_clear(pac_set_t* set) {
	// Stop if the ROM set is null.
	if (!set) {
		printf("Error (pac_set_clear): ROM set pointer is null.\n");
		return -1;
	}
	// Free the ROMs array.
	free(set->roms);
	// Nullify the properties.
	set->roms = NULL;
	set->size = 0;
	return 0;
}

// Destroys the ROM set.
void pac_set_destroy(pac_set_t* set) {
	// Stop if the ROM set is null.
	if (!set) {
		printf("Error (pac_set_destroy): ROM set pointer is null.\n");
		return;
	}
	pac_set_clear(set);
	free(set);
}

// Returns the size of the ROM set.
size_t pac_set_get_size(const pac_set_t* set) {
	return set ? set->size : 0;
}

// Returns the ROM array in the set.
pac_rom_t** pac_set_get_roms(const pac_set_t* set) {
	return set ? set->roms : NULL;
}

// Returns the address of a ROM file.
const pac_rom_t* pac_set_get_rom(const pac_set_t* set, const size_t index) {
	// Stop if the ROM set is null.
	if (!set) {
		printf("Error (pac_set_get_rom): ROM set pointer is null.\n");
		return NULL;
	}
	// Fail if the ROM set's array is null.
	if (!set->roms) {
		printf("Error (pac_set_get_rom): ROM set's ROM array is null.\n");
		return NULL;
	}
	// Return the address.
	return set->roms[index];
}

// Changes the array size of a ROM set.
int pac_set_change_size(pac_set_t* set, const size_t size) {
	// Stop if the ROM set is null.
	if (!set) {
		printf("Error (pac_set_change_size): ROM set pointer is null.\n");
		return -1;
	}
	set->size = size;
	set->roms = (pac_rom_t**) realloc(set->roms, sizeof(pac_rom_t*) * size);
	// Fail if the ROMs array didn't reallocate.
	if (!set->roms) {
		printf("Error (pac_set_change_size): ROM set array failed to reallocate.\n");
		return -1;
	}
	return 0;
}

// Appends a ROM into the set.
int pac_set_append_rom(pac_set_t* set, pac_rom_t* rom) {
	// Stop if the ROM set is null.
	if (!set) {
		printf("Error (pac_set_append_rom): ROM set pointer is null.\n");
		return -1;
	}
	// Stop if the ROM is null.
	if (!rom) {
		printf("Error (pac_set_append_rom): ROM pointer is null.\n");
		return -1;
	}
	// Fail if changing the size didn't work.
	if (pac_set_change_size(set, set->size + 1)) {
		printf("Error (pac_set_append_rom): Couldn't change size of the ROM array.\n");
		return -1;
	}
	set->roms[set->size - 1] = rom;
	return 0;
}
