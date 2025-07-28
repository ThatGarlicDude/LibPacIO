#include <libpacio.h>

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
