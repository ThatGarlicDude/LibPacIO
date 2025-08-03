// TODO: Maybe have this whole thing put and packaged into LibPacIO as a shared library.

#include <libpacio.h>
#include <string.h>
#include <sys/stat.h>
#include "main.h"

#define DEFAULT_PATH "."

char* path;

// Sets the file path for the LibPacIO test. Fails if the path is invalid.
int libpacio_set_path(const char* new_path) {
	struct stat sb;
	// Is the file valid?
	if (stat(new_path, &sb)) {
		perror("Not a valid path.\n");
		return -1;
	}
	// Is the file a directory?
	if (!S_ISDIR(sb.st_mode)) {
		perror("Not a directory.\n");
		return -1;
	}
	// Did the string duplication work?
	if (!(path = strdup(new_path))) {
		perror("Strdup failed.\n");
		return -1;
	}
	return 0;
}

// Gets the file path for the LibPacIO test.
const char* libpacio_get_path(void) {
	return path;
}

// Clears and frees the file path for the LibPacIO test.
void libpacio_clear_path(void) {
	if (!path) return;
	memset(path, 0, strlen(path));
	free(path);
	path = NULL;
	return;
}
