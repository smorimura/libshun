/*
 * getparam.c		by Shun Morimura
 */
#include <string.h>
#include "libshun.h"

char SH_GetComParameter(const char *com_param, char *com_opt_arg, const char *special_opt_letters)
{
	if (com_param[0] == '-') {
		if (com_param[1] == '\0') {		/* in case of '-' only */
			SH_ErrorExit("only '-' specified as command option.\n");
		}
		if (strchr(special_opt_letters, com_param[1]) != NULL) {	/* in case of special option letter */
			if (strlen(com_param + 2) >= COM_OPT_ARG_SIZE) {
				SH_ErrorExit("too long command option argument.\n");
			}
			strncpy(com_opt_arg, com_param + 2, COM_OPT_ARG_SIZE);
		}
		return(com_param[1]);
	} else {
		return('\0');		/* in case of command argument */
	}
}

