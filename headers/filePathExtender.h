#include "filePathArray.h"

#ifndef FILE_PATH_EXTENDER_H
#define FILE_PATH_EXTENDER_H

	void changeSize(FilePathArray* filePathArray, size_t size);

	void addFilePath(FilePathArray* filePathArray, const char* filePath, int index);

	void removeFilePath(FilePathArray* filePathArray, int index);

	void pushFilePath(FilePathArray* filePathArray, const char* filePath);

#endif
