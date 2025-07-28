#include <libpacio.h>

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
