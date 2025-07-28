#include <libpacio.h>

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
