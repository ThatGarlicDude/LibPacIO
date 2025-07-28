#include <libpacio.h>

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
