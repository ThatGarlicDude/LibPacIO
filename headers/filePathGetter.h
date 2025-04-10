#include <stdio.h>
#include "filePathArray.h"

#ifndef FILE_PATH_GETTER_H
#define FILE_PATH_GETTER_H

	FilePathArray* getFilePathArray(FilePathArray* filePathArray);

	const char* getFilePath(FilePathArray* filePathArray, int index);

	const char** getFilePaths(FilePathArray* filePathArray);

	size_t* getSize(FilePathArray* filePathArray);

#endif
