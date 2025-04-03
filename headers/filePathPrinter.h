#ifndef FILE_PATH_PRINTER_H
#define FILE_PATH_PRINTER_H

	#include <stdio.h>
	#include "filePathArray.h"

	void printFilePath(FilePathArray* filePathArray, int index);

	void printAllFilePaths(FilePathArray* filePathArray);

	void printFilePathPointer(FilePathArray* filePathArray, int index);

	void printAllFilePathPointers(FilePathArray* filePathArray);
#endif
