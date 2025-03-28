#include <stdio.h>
#include "filePathArray.h"
#include "filePathGetter.h"
#include "filePathPrinter.h"
#include "nullHandler.h"
#include "romSet.h"
#include "stringAdder.h"

// Main function.
int main(int argc, char* argv[]) {
	FilePathArray paths = newFilePathArray(3);
	printAllFilePaths(&paths);
	return 0;
}
