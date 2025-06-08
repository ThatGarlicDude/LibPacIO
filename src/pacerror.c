#include <stdio.h>
#include <stdint.h>
#include "pacerror.h"

// ANSI colors.
const char* COLOR_DEFAULT = "\033[0m";
const char* COLOR_INFO = "\033[36m";
const char* COLOR_WARN = "\033[33m";
const char* COLOR_ERROR = "\033[31m";

// Tells whether pac_info would actually print.
const uint8_t PAC_INFO_VERBOSE = 0;

// Prints info on the terminal.
void pac_info(const char* function_name, const char* message) {
	if (PAC_INFO_VERBOSE) return;
	printf("%s%s:%s %s\n", COLOR_INFO, function_name, COLOR_DEFAULT, message);
	return;
}

// Prints a warning on the terminal.
void pac_warn(const char* function_name, const char* message) {
	printf("%sWarning (%s):%s %s\n", COLOR_WARN, function_name, COLOR_DEFAULT, message);
	return;
}

// Prints an error message on the terminal.
void pac_error(const char* function_name, const char* message) {
	printf("%sError (%s):%s %s\n", COLOR_ERROR, function_name, COLOR_DEFAULT, message);
	return;
}
