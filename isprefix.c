/*
 * isprefix.c		by Shun Morimura
 */
#include <string.h>
#include "libshun.h"

SH_bool SH_IsPrefix(const char *prefix, const char *buffer)
{
	if (strncmp(prefix, buffer, strlen(prefix)) == 0) {
		return(TRUE);
	} else {
		return(FALSE);
	}
}

