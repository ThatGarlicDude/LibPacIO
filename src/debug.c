#include <stdio.h>
#include "filePathArray.h"
#include "filePathGetter.h"
#include "filePathPrinter.h"
#include "romSet.h"

// Main function.
int main(int argc, char* argv[]) {
	FilePathArray paths = newFilePathArray(3);
	size_t* size = getSize(&paths);
	const char** filePaths = getFilePaths(&paths);
	printf("Memory location of size in the array is %p.\n", &(paths.size));
	printf("Memory location of size is %p.\n", size);
	printf("Memory location of filePaths in the array is %p.\n", paths.filePaths);
	printf("Memory location of filePaths is %p.\n", filePaths);
	printf("Size of array is: %zu.\n", *size);
	printf("Let's get something in the array...\n");
	printf("FilePath in index 0 is %s.\n", filePaths[0]);
	printf("Let's get all the filePaths in the array.\n");
	printAllFilePaths(&paths);
	printf("Let's add something to the array...\n");
	filePaths[0] = "Hello!";
	printf("Now let's print the array...\n");
	printAllFilePaths(&paths);
	return 0;
}
