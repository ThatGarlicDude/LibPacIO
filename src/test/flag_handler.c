#include <libpacio.h>
#include <string.h>
#include "main.h"

#define FLAG_VERSION "-v"
#define FLAG_PATH "-p"
#define FLAG_HELP "--help"

#define DEFAULT_INDEX 1

int libpacio_index = DEFAULT_INDEX;

// Handle the command-line options for the LibPacIO Test.
int libpacio_handle_flags(int argc, char* argv[]) {
	while (libpacio_index < argc) {
		if (strcmp(argv[libpacio_index], FLAG_VERSION) == 0) {
			// VERSION.
			version_test();
			libpacio_index += 1;
			continue;
		} else if (strcmp(argv[libpacio_index], FLAG_PATH) == 0) {
			// PATH.
			libpacio_set_path(argv[libpacio_index + 1]);
			libpacio_index += 2;
			continue;
		} else if (strcmp(argv[libpacio_index], FLAG_HELP) == 0) {
			// HELP.
			libpacio_print_help();
			libpacio_index += 1;
			continue;
		} else {
			// Print the help menu if none of the requirements are met.
			libpacio_print_help();
			return -1;
		}
	}
	// Success!
	return 0;
}
