#include "pacrom.h"
#include "pacset.h"

#ifndef PACPRINT_H
#define PACPRINT_H

	// Prints the entire ROM data.
	void pac_rom_printd(const pac_rom_t* rom);

	// Prints information about a ROM file.
	void pac_rom_print(const pac_rom_t* rom);

	// Prints all the pointers in the ROM set array.
	void pac_set_printp(const pac_set_t* set);

	// Prints the entire data of a ROM set.
	void pac_set_print(const pac_set_t* set);

#endif
