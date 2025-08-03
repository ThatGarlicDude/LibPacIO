#include <libpacio.h>
#include "flag_handler.h"
#include "path_handler.h"
#include "version_print.h"
#include "help.h"

// Main function.
int main(int argc, char* argv[]) {
	libpacio_set_path(DEFAULT_PATH);
	libpacio_handle_flags(argc, argv);
	return 0;
}
