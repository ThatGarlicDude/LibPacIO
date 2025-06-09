#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacset.h"
#include "pacrom.h"
#include "pacsort.h"
#include "pacio.h"
#include "paclimits.h"
#include "pacerror.h"

// Private function names.
const char* NAME_PAC_SET_INIT = "pac_set_init";
const char* NAME_PAC_SET_CREATE = "pac_set_create";
const char* NAME_PAC_SET_CLEAR = "pac_set_clear";
const char* NAME_PAC_SET_DESTROY = "pac_set_destroy";
const char* NAME_PAC_SET_COPY = "pac_set_copy";
const char* NAME_PAC_SET_DUPLICATE = "pac_set_duplicate";
const char* NAME_PAC_SET_GET_PATH = "pac_set_get_path";
const char* NAME_PAC_SET_GET_SIZE = "pac_set_get_size";
const char* NAME_PAC_SET_GET_ROMS = "pac_set_get_roms";
const char* NAME_PAC_SET_GET_ROM = "pac_set_get_rom";
const char* NAME_PAC_SET_APPEND_ROM = "pac_set_append_rom";

// The pre-made size for pac_set_t.
const size_t PAC_SET_SIZE = sizeof(pac_set_t);

// Initializes a new ROM set.
void pac_set_init(pac_set_t* set, const char* path) {
	pac_info(NAME_PAC_SET_INIT, "Initiating the ROM set...");
	if (!set) {
		pac_warn(NAME_PAC_SET_INIT, "ROM set pointer is NULL!");
		return;
	}
	pac_info(NAME_PAC_SET_INIT, "Copying string to the ROM set's path...");
	strncpy(set->path, path, PAC_PATH_MAX - 1);
	set->path[PAC_PATH_MAX - 1] = '\0';
	pac_info(NAME_PAC_SET_INIT, "Setting size of the ROM set...");
	set->size = 0;
	pac_info(NAME_PAC_SET_INIT, "Setting the ROMs array with zeroes...");
	memset(set->roms, 0, PAC_ROMS_MAX);
	pac_info(NAME_PAC_SET_INIT, "Successfully initiated ROM set!");
	return;
}

// Creates a new ROM set.
pac_set_t* pac_set_create(const char* path) {
	pac_info(NAME_PAC_SET_CREATE, "Creating the ROM set...");
	pac_set_t* set = (pac_set_t*) malloc(PAC_SET_SIZE);
	if (!set) {
		pac_error(NAME_PAC_SET_CREATE, "Failed to allocate ROM set.");
		return NULL;
	}
	pac_info(NAME_PAC_SET_CREATE, "ROM set allocation successful! Now initiating the ROM set...");
	pac_set_init(set, path);
	pac_set_scan_directory(set);
	pac_set_sort(set);
	pac_info(NAME_PAC_SET_CREATE, "Successfully created ROM set!");
	return set;
}

// Clears the ROM set.
void pac_set_clear(pac_set_t* set) {
	pac_info(NAME_PAC_SET_CLEAR, "Clearing ROM set...");
	if (!set) {
		pac_warn(NAME_PAC_SET_CLEAR, "ROM set pointer is NULL!");
		return;
	}
	pac_info(NAME_PAC_SET_CLEAR, "Going through each of the ROMs...");
	for (size_t index = 0; index < set->size; index++) {
		if (!set->roms[index]) {
			continue;
		}
		pac_info(NAME_PAC_SET_CLEAR, "Found ROM! Destroying it...");
		pac_rom_destroy(set->roms[index]);
	}
	pac_info(NAME_PAC_SET_CLEAR, "Cleaning the ROM set with zeroes...");
	memset(set, 0, PAC_SET_SIZE);
	pac_info(NAME_PAC_SET_CLEAR, "Successfully cleared ROM set!");
	return;
}

// Destroys the ROM set.
void pac_set_destroy(pac_set_t* set) {
	pac_info(NAME_PAC_SET_DESTROY, "Destroying ROM set...");
	if (!set) {
		pac_warn(NAME_PAC_SET_DESTROY, "ROM set pointer is NULL!");
		return;
	}
	pac_set_clear(set);
	free(set);
	pac_info(NAME_PAC_SET_DESTROY, "Successfully destroyed ROM set!");
	return;
}

// Copies a ROM set source to a destination.
void pac_set_copy(const pac_set_t* set_source, pac_set_t* set_destination) {
	pac_info(NAME_PAC_SET_COPY, "Copying a ROM set to another...");
	if (!set_source || !set_destination) {
		pac_warn(NAME_PAC_SET_COPY, "Either ROM set source or destination pointers are NULL!");
		return;
	}
	pac_info(NAME_PAC_SET_COPY, "Going through each byte of the struct to copy...");
	memcpy(set_destination, set_source, PAC_SET_SIZE);
	pac_info(NAME_PAC_SET_COPY, "Successfully copied ROM set!");
	return;
}

// Duplicates a ROM set to a destination.
pac_set_t* pac_set_duplicate(const pac_set_t* set_source) {
	pac_info(NAME_PAC_SET_DUPLICATE, "Duplicating the ROM set...");
	if (!set_source) {
		pac_warn(NAME_PAC_SET_DUPLICATE, "ROM set source pointer is NULL!");
		return NULL;
	}
	pac_set_t* set_destination = pac_set_create(set_source->path);
	if (set_destination) {
		pac_set_copy(set_source, set_destination);
		pac_info(NAME_PAC_SET_DUPLICATE, "Successfully duplicated the ROM set!");
		return set_destination;
	} else {
		pac_error(NAME_PAC_SET_DUPLICATE, "Failed to duplicate ROM set.");
		return NULL;
	}
}

// Returns the filepath of the ROM set.
const char* pac_set_get_path(const pac_set_t* set) {
	if (!set) {
		pac_warn(NAME_PAC_SET_GET_PATH, "ROM set pointer is NULL!");
		return NULL;
	}
	return set->path;
}

// Returns the size of the ROM set.
size_t pac_set_get_size(const pac_set_t* set) {
	if (!set) {
		pac_warn(NAME_PAC_SET_GET_SIZE, "ROM set pointer is NULL!");
		return 0;
	}
	return set->size;
}

// Returns the ROMs array in the ROM set.
pac_rom_t* const* pac_set_get_roms(const pac_set_t* set) {
	if (!set) {
		pac_warn(NAME_PAC_SET_GET_ROMS, "ROM set pointer is NULL!");
		return NULL;
	}
	return set ? set->roms : NULL;
}

// Returns the address of a ROM file.
const pac_rom_t* pac_set_get_rom(const pac_set_t* set, const size_t index) {
	if (!set) {
		pac_warn(NAME_PAC_SET_GET_ROM, "ROM set pointer is NULL!");
		return NULL;
	}
	return set->roms[index];
}

// Appends a ROM into the set.
int pac_set_append_rom(pac_set_t* set, pac_rom_t* rom) {
	pac_info(NAME_PAC_SET_APPEND_ROM, "Appending a ROM into the ROM set...");
	if (!set || !rom) {
		pac_warn(NAME_PAC_SET_APPEND_ROM, "Either the ROM set or ROM pointers are NULL!");
		return -1;
	}
	set->roms[set->size++] = rom;
	pac_info(NAME_PAC_SET_APPEND_ROM, "Successfully appended the ROM!");
	return 0;
}
