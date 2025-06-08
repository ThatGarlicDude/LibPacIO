#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "pacrom.h"
#include "pacset.h"
#include "pacio.h"
#include "pacprint.h"

// Main function.
int main(int argc, char* argv[]) {
	char* cwd = pac_path_generate("./");
	pac_set_t* set = pac_set_create(cwd);
	pac_path_clear(cwd);
	pac_set_print(set);
	pac_set_destroy(set);
	return 0;
}
