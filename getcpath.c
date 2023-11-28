/*
 * getcpath.c		by Shun Morimura
 */
#include <string.h>

char *SH_GetCommandPath(const char *argv0, char *com_path)
{
	char *unix_delimiter;	/* pointer to '/' */
	char *dos_delimiter;	/* pointer to '\' */
	char *dos_drive;	/* pointer to ':' */

	unix_delimiter = strrchr(argv0, '/');
	dos_delimiter  = strrchr(argv0, '\\');
	dos_drive      = strrchr(argv0, ':');

	if ((unix_delimiter != NULL) || (dos_delimiter != NULL)) {
		if (unix_delimiter > dos_delimiter) {	/* such as '/home/user/bin/example' on Unix */
			strncpy(com_path, argv0, unix_delimiter - argv0 + 1);
		} else {	/* such as 'A:\BIN\EXAMPLE.EXE' on DOS/Windows */
			strncpy(com_path, argv0, dos_delimiter  - argv0 + 1);
		}
	} else {
		if (dos_drive != NULL) {	/* such as 'B:EXAMPLE.EXE' on DOS/Windows */
			strncpy(com_path, argv0, dos_drive - argv0 + 1);
		}
	}

	return(com_path);
}

