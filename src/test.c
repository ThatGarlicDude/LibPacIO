#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "pacrom.h"
#include "pacset.h"
#include "pacsort.h"
#include "pacio.h"
#include "pacprint.h"
#include "pacerror.h"

void rom_set_test(void) {
	char* cwd = pac_path_generate("./");
	pac_set_t* set = pac_set_create(cwd);
	pac_path_clear(cwd);
	pac_set_print(set);
	pac_set_destroy(set);
}

void rom_swap_test(void) {
	pac_rom_t* rom1 = pac_rom_create("Rom.4a");
	pac_rom_t* rom2 = pac_rom_create("Rom.27");
	pac_info("rom_swap_test", "Before swapping...");
	pac_rom_print(rom1);
	pac_rom_print(rom2);
	pac_rom_swap(&rom1, &rom2);
	pac_info("rom_swap_test", "After swapping...");
	pac_rom_print(rom1);
	pac_rom_print(rom2);
	pac_rom_destroy(rom1);
	pac_rom_destroy(rom2);
}

// Main function.
int main(int argc, char* argv[]) {
	rom_set_test();
	return 0;
}
