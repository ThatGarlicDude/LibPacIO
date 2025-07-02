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

// Sets up a PacROM struct.
void pac_rom_init(pac_rom_t* rom, const char* path) {
	if (!rom) return;
	rom->path = strdup(path);
	rom->size = 0;
	rom->data = NULL;
	return;
}

// Creates a new PacROM into memory.
pac_rom_t* pac_rom_create(const char* path) {
	pac_rom_t* rom = (pac_rom_t*) malloc(sizeof(pac_rom_t));
	if (!rom) return NULL;
	pac_rom_init(rom, path);
	return rom;
}

// Clears a PacROM with zeroes.
void pac_rom_clear(pac_rom_t* rom) {
	if (!rom) return;
	// Clean the path of the PacROM.
	if (rom->path) {
		memset(rom->path, 0, strlen(rom->path));
		free(rom->path);
	}
	memset(rom, 0, sizeof(pac_rom_t));
	return;
}

// Destroys a PacROM from memory.
void pac_rom_destroy(pac_rom_t* rom) {
	if (!rom) return;
	pac_rom_clear(rom);
	free(rom);
	return;
}

/*
	## FILE FUNCTIONS ##
*/

// Creates a new PacROM and loads its ROM file's data.
pac_rom_t* pac_rom_load(const char* path) {
	// Declare these variables.
	pac_rom_t* rom = pac_rom_create(path);
	FILE* file = fopen(path, "rb");
	if (!rom || !file) {
		free(rom);
		fclose(file);
		return NULL;
	}
	// Assign the size of the PacROM.
	fseek(file, 0, SEEK_END);
	rom->size = ftell(file);
	rewind(file);
	if (rom->size < 0) {
		free(rom);
		fclose(file);
		return NULL;
	}
	// Assign the data of the PacROM.
	rom->data = malloc(rom->size);
	if (!rom->data) {
		free(rom);
		fclose(file);
		return NULL;
	}
	fread(rom->data, rom->size, sizeof(uint8_t), file);
	// Success!
	fclose(file);
	return rom;
}

// Clears all data regarding a PacROM, and frees it from memory.
void pac_rom_unload(pac_rom_t* rom) {
	if (!rom) return;
	// Clear and free the data inside the PacROM.
	memset(rom->data, 0, rom->size);
	free(rom->data);
	// Then destroy it from memory.
	pac_rom_destroy(rom);
	return;
}

// Saves information to a ROM file using a PacROM's data.
void pac_rom_save(const pac_rom_t* rom) {
	FILE* file = fopen(rom->path, "wb");
	// Stop if these don't exist.
	if (!rom || !rom->data || !file) {
		fclose(file);
		return;
	}
	fwrite(rom->data, sizeof(uint8_t), rom->size, file);
	// Success!
	fclose(file);
	return;
}

/*
	## READ FUNCTIONS ##
*/

// Reads a single byte from a PacROM's memory.
uint8_t pac_rom_read(const pac_rom_t* rom, const off_t offset) {
	if (!rom || !rom->data) return 0;
	return rom->data[offset];
}

// Read multiple bytes from a PacROM's memory.
uint8_t* pac_rom_readn(const pac_rom_t* rom, const off_t offset, const size_t size) {
	uint8_t* bytes = malloc(size);
	if (!bytes) return NULL;
	for (size_t index = 0; index < size; index++) {
		bytes[index] = pac_rom_read(rom, index + offset);
	}
	return bytes;
}

// Read all bytes from a PacROM's memory.
uint8_t* pac_rom_read_all(const pac_rom_t* rom) {
	return pac_rom_readn(rom, 0, rom->size);
}

/*
	## WRITE FUNCTIONS ##
*/

// Writes a single byte from a PacROM's memory.
void pac_rom_write(pac_rom_t* rom, const off_t offset, const uint8_t byte) {
	if (!rom || !rom->data) return;
	rom->data[offset] = byte;
	return;
}

// Writes multiple bytes from a PacROM's memory.
void pac_rom_writen(pac_rom_t* rom, const off_t offset, const uint8_t* bytes, const size_t size) {
	for (size_t index = 0; index < size; index++) {
		pac_rom_write(rom, index + offset, bytes[index]);
	}
	return;
}

/*
	## GETTER FUNCTIONS ##
*/

// Returns the path of the PacROM.
char* pac_rom_get_path(const pac_rom_t* rom) {
	return rom ? rom->path : NULL;
}

// Returns the size of the PacROM.
size_t pac_rom_get_size(const pac_rom_t* rom) {
	return rom ? rom->size : 0;
}

// Returns the data of the PacROM.
uint8_t* pac_rom_get_data(const pac_rom_t* rom) {
	return rom ? rom->data : NULL;
}
