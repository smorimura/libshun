/*
 * errexit.c		by Shun Morimura
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int SH_ErrorExit(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "ERROR: ");
	vfprintf(stderr, fmt, args);
	va_end(args);

	exit(EXIT_FAILURE);

	return(EXIT_FAILURE);	/* dummy */
}

