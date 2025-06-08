#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "pacrom.h"
#include "pacio.h"
#include "paclimits.h"
#include "pacerror.h"

// Private function names.
const char* NAME_PAC_ROM_INIT = "pac_rom_init";
const char* NAME_PAC_ROM_CREATE = "pac_rom_create";
const char* NAME_PAC_ROM_CLEAR = "pac_rom_clear";
const char* NAME_PAC_ROM_DESTROY = "pac_rom_destroy";
const char* NAME_PAC_ROM_COPY = "pac_rom_copy";
const char* NAME_PAC_ROM_DUPLICATE = "pac_rom_duplicate";
const char* NAME_PAC_ROM_GET_NAME = "pac_rom_get_name";
const char* NAME_PAC_ROM_GET_SIZE = "pac_rom_get_size";
const char* NAME_PAC_ROM_GET_DATA = "pac_rom_get_data";

// The pre-made size for pac_rom_t.
const size_t PAC_ROM_SIZE = sizeof(pac_rom_t);

// Initiates a new ROM.
void pac_rom_init(pac_rom_t* rom, const char* name) {
	pac_info(NAME_PAC_ROM_INIT, "Initiating the ROM...");
	if (!rom) {
		pac_warn(NAME_PAC_ROM_INIT, "ROM pointer is NULL!");
		return;
	}
	pac_info(NAME_PAC_ROM_INIT, "Copying string to the ROM's name...");
	strncpy(rom->name, name, PAC_NAME_MAX);
	rom->name[PAC_NAME_MAX] = '\0';
	pac_info(NAME_PAC_ROM_INIT, "Initiating the ROM's other properties...");
	rom->size = 0;
	rom->data = NULL;
	pac_info(NAME_PAC_ROM_INIT, "Successfully initiated the ROM!");
	return;
}

// Creates a new ROM.
pac_rom_t* pac_rom_create(const char* name) {
	pac_info(NAME_PAC_ROM_CREATE, "Creating the ROM...");
	pac_rom_t* rom = (pac_rom_t*) malloc(PAC_ROM_SIZE);
	if (!rom) {
		pac_error(NAME_PAC_ROM_CREATE, "Failed to allocate ROM.");
		return NULL;
	}
	pac_info(NAME_PAC_ROM_CREATE, "ROM allocation successful! Now initiating the ROM...");
	pac_rom_init(rom, name);
	pac_info(NAME_PAC_ROM_CREATE, "Successfully created the ROM!");
	return rom;
}

// Clear the ROM.
void pac_rom_clear(pac_rom_t* rom) {
	pac_info(NAME_PAC_ROM_CLEAR, "Clearing the ROM...");
	if (!rom) {
		pac_warn(NAME_PAC_ROM_CLEAR, "ROM pointer is NULL!");
		return;
	}
	pac_info(NAME_PAC_ROM_CLEAR, "Proceeding to unload the ROM...");
	pac_rom_unload(rom);
	pac_info(NAME_PAC_ROM_CLEAR, "Freeing the ROM data...");
	free(rom->data);
	pac_info(NAME_PAC_ROM_CLEAR, "Clearing the ROM with zeroes...");
	memset(rom, 0, PAC_ROM_SIZE);
	pac_info(NAME_PAC_ROM_CLEAR, "Successfully cleared the ROM!");
	return;
}

// Destroy the ROM.
void pac_rom_destroy(pac_rom_t* rom) {
	pac_info(NAME_PAC_ROM_DESTROY, "Destroying the ROM...");
	if (!rom) {
		pac_warn(NAME_PAC_ROM_DESTROY, "ROM pointer is NULL!");
		return;
	}
	pac_rom_clear(rom);
	free(rom);
	pac_info(NAME_PAC_ROM_DESTROY, "Successfully destroyed the ROM!");
	return;
}

// Copies a ROM source to a destination.
void pac_rom_copy(const pac_rom_t* rom_source, pac_rom_t* rom_destination) {
	pac_info(NAME_PAC_ROM_COPY, "Copying a ROM to another...");
	if (!rom_source || !rom_destination) {
		pac_warn(NAME_PAC_ROM_COPY, "Either ROM source or destination pointers are NULL!");
		return;
	}
	pac_info(NAME_PAC_ROM_COPY, "Going through each byte of the struct to copy...");
	for (size_t index = 0; index < PAC_ROM_SIZE; index++) {
		rom_destination[index] = rom_source[index];
	}
	pac_info(NAME_PAC_ROM_COPY, "Successfully copied ROM!");
	return;
}

// Duplicates a ROM to a destination.
pac_rom_t* pac_rom_duplicate(const pac_rom_t* rom_source) {
	pac_info(NAME_PAC_ROM_DUPLICATE, "Duplicating the ROM...");
	if (!rom_source) {
		pac_warn(NAME_PAC_ROM_DUPLICATE, "ROM source pointer is NULL!");
		return NULL;
	}
	pac_rom_t* rom_destination = pac_rom_create(rom_source->name);
	if (rom_destination) {
		pac_rom_copy(rom_source, rom_destination);
		pac_info(NAME_PAC_ROM_DUPLICATE, "Successfully duplicated the ROM!");
		return rom_destination;
	} else {
		pac_error(NAME_PAC_ROM_DUPLICATE, "Failed to duplicate ROM.");
		return NULL;
	}
}

// Returns a ROM's filename.
const char* pac_rom_get_name(const pac_rom_t* rom) {
	pac_info(NAME_PAC_ROM_GET_NAME, "Getting the filename from the ROM...");
	if (!rom) {
		pac_warn(NAME_PAC_ROM_GET_NAME, "ROM pointer is NULL!");
		return NULL;
	}
	pac_info(NAME_PAC_ROM_GET_NAME, "Successfully got the ROM name!");
	return rom->name;
}

// Returns a ROM's size.
size_t pac_rom_get_size(const pac_rom_t* rom) {
	pac_info(NAME_PAC_ROM_GET_SIZE, "Getting the size from the ROM...");
	if (!rom) {
		pac_warn(NAME_PAC_ROM_GET_SIZE, "ROM pointer is NULL!");
		return 0;
	}
	pac_info(NAME_PAC_ROM_GET_SIZE, "Successfully got the ROM size!");
	return rom->size;
}

// Returns a ROM's data.
const uint8_t* pac_rom_get_data(const pac_rom_t* rom) {
	pac_info(NAME_PAC_ROM_GET_DATA, "Getting the data pointer from the ROM...");
	if (!rom) {
		pac_warn(NAME_PAC_ROM_GET_DATA, "ROM pointer is NULL!");
		return NULL;
	}
	pac_info(NAME_PAC_ROM_GET_DATA, "Successfully got the ROM data pointer!");
	return rom->data;
}

