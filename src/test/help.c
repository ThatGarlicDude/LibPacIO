#include <libpacio.h>
#include <stdint.h>
#include "main.h"

#define LIBPACIO_OPTION_SIZE sizeof(libpacio_option_t)
#define LIBPACIO_OPTION_AMOUNT (sizeof(options) / LIBPACIO_OPTION_SIZE)
#define LIBPACIO_OPTION_LIMIT 3

typedef struct libpacio_option {
	const char* flag;
	const char* argument;
	const char* description;
} libpacio_option_t;

libpacio_option_t options[] = {
	{FLAG_VERSION,	NULL,		"Prints the current version of LibPacIO."},
	{FLAG_PATH,		"<path>",	"Sets the file path for LibPacIO (Default: '.')."},
	{FLAG_HELP,		NULL,		"Prints the help menu."}
};

// Prints the help menu for LibPacIO.
void libpacio_print_help(void) {
	size_t amount = LIBPACIO_OPTION_AMOUNT;
	printf("%s Options", LIBPACIO_NAME);
	for (size_t index = 0; index < amount; index++) {
		libpacio_print_option(index);
	}
	return;
}

// Prints a specific option to the terminal.
void libpacio_print_option(const size_t index) {
	printf("\n\t%s ", options[index].flag);
	if (options[index].argument) {
		printf("%s ", options[index].argument);
	}
	printf("= %s\n", options[index].description);
	return;
}
