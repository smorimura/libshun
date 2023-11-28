/*
 * cutnline.c		by Shun Morimura
 */
#include <string.h>

char *SH_CutNewLineByte(char *line)
{
	size_t length;

	length = strlen(line);
	if (line[length - 1] == '\n') {
		line[length - 1] = '\0';
	}

	return(line);
}

