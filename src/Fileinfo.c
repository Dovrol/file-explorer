//
// Created by Wiktor Kubis on 08/01/2020.
//

#include "Functions.h"
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

void fileInfo(char *f, char *lastModified, char *size) {
	struct stat attr;
	stat(f, &attr);
	strftime(lastModified, 100, "%d/%m/%Y %H:%M:%S", localtime(&attr.st_mtime));
	if (attr.st_size >= 1000000000 && attr.st_size < 9999999999) {
		sprintf(size, "%lld GB", attr.st_size / 1000000000);
	} else if (attr.st_size >= 1000000 && attr.st_size < 9999999) {
		sprintf(size, "%lld MB", attr.st_size / 1000000);
	} else if (attr.st_size >= 1000 && attr.st_size < 9999) {
		sprintf(size, "%lld KB", attr.st_size / 1000);
	} else if (attr.st_size < 1000) {
		sprintf(size, "%lld B", attr.st_size);
	} else {
		sprintf(size, "Unknown");
	}

}