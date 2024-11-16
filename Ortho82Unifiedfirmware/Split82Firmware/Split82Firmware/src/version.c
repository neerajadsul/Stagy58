#include <stdio.h>
#include <string.h>
#include "version.h"

const int MAJOR = 0;
const int MINOR = 1;
const int PATCH = 8;

const char TIMESTAMP[20] = "2024-11-16_21:30:38";

char* get_semantic_version()
{
	static char sem_ver[30];
	sprintf(sem_ver, "%d.%d.%d_%s", MAJOR, MINOR, PATCH, TIMESTAMP);
	//strcat(sem_ver, TIMESTAMP);
	return sem_ver;
}

