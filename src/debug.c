#include <stdio.h>
#include "filePathArray.h"
#include "romSet.h"

// Main function.
int main(int argc, char* argv[]) {
	printf("Alright.\n");
	FilePathArray paths = newEmptyFilePathArray();
	printf("Size of array is: %zu\n", paths.size);
	return 0;
}
