#include <libpacio.h>

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
