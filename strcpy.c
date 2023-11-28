/*
 * strcpy.c		by Shun Morimura
 */
#include <string.h>

char *SH_StringCopy(char *dst, const char *src, size_t size)
{
	strncpy(dst, src, size);
	dst[size] = '\0';

	return(dst);
}

