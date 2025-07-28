#include <libpacio.h>

// TODO: Rework this function somehow. Maybe make it generic instead of relying on PacROMSet.

// Concats a PacROMSet's path and a ROM's name together.
char* pac_romset_concat(const pac_romset_t* romset, size_t index) {
	if (!romset) return NULL;
	size_t romset_path_length = strlen(romset->path);
	size_t rom_name_length = strlen(romset->roms[index]);
	size_t concatted_length = romset_path_length + rom_name_length + 2; // Make room for the '/' in between, and the null terminator at the end.
	char* concatted_path = malloc(concatted_length);
	snprintf(concatted_path, concatted_length, "%s/%s", romset->path, romset->roms[index]);
	return concatted_path;
}
