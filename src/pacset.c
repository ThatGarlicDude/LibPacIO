#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacset.h"
#include "pacrom.h"
#include "paclimits.h"

// Initializes a new ROM set.
void pac_set_init(pac_set_t* set, const char* path) {
	// Stop if the ROM set is null.
	if (!set) {
		printf("Error (pac_set_init): ROM set pointer is null.\n");
		return;
	}
	// Safely copy the path to the ROM set's path.
	strncpy(set->path, path, PAC_PATH_MAX);
	set->path[PAC_PATH_MAX] = '\0';
	return;
}

// Creates a new ROM set.
pac_set_t* pac_set_create(const char* path) {
	// Allocate the ROM set.
	pac_set_t* set = calloc(1, sizeof(pac_set_t));
	// Stop if the allocation failed.
	if (!set) {
		free(set);
		return NULL;
	}
	// Initialize the ROM set.
	pac_set_init(set, path);
	// Return the set.
	return set;
}

// Clears the ROM set.
void pac_set_clear(pac_set_t* set) {
	// Stop if the ROM set is null.
	if (!set) {
		printf("Error (pac_set_clear): ROM set pointer is null.\n");
		return;
	}
	// Go through each of the ROMs in the array.
	for (size_t index = 0; index < set->size; index++) {
		// If a ROM is null, just continue to the next.
		if (!set->roms[index]) {
			continue;
		}
		// Clear the ROM.
		pac_rom_clear(set->roms[index]);
	}
	// Clean the ROM set.
	memset(set, 0, sizeof(pac_set_t));
	return;
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
	return;
}

// Returns the filepath of the ROM set.
const char* pac_set_get_path(const pac_set_t* set) {
	return set ? set->path : NULL;
}

// Returns the size of the ROM set.
size_t pac_set_get_size(const pac_set_t* set) {
	return set ? set->size : 0;
}

// Returns the ROMs array in the ROM set.
pac_rom_t* const* pac_set_get_roms(const pac_set_t* set) {
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
	// Push the ROM onto the array.
	set->roms[set->size] = rom;
	set->size++;
	return 0;
}
