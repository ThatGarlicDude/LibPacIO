#include <libpacio.h>

// Prints all information about LibPacIO.
void libpacio_print() {
	libpacio_print_name();
	libpacio_print_version();
	libpacio_print_disclaimer();
	return;
}

// Prints the name of the project.
void libpacio_print_name() {
	printf("%s\n", LIBPACIO_NAME);
	return;
}

// Prints the version of the project.
void libpacio_print_version() {
	printf("Version: %s\n", LIBPACIO_VERSION);
	return;
}

// Prints the disclaimer of the project.
void libpacio_print_disclaimer() {
	printf("This utility is not an official product of Bandai Namco or AtGames.\n");
	printf("It is made and developed by GarlicDude for educational and research purposes.\n");
	return;
}
