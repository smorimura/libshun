/*
 * isfile.c		by Shun Morimura
 */
#include <stdio.h>
#include "libshun.h"

SH_bool SH_IsFile(const char *filename)
{
	FILE *fp;

	if ((fp = fopen(filename, "r")) == NULL) {
		return(FALSE);
	} else {
		fclose(fp);
		return(TRUE);
	}
}

