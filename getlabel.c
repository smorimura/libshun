/*
 * getlabel.c		by Shun Morimura
 */
#include <string.h>
#include "libshun.h"

int SH_GetLabelAndDescription(const char *line, const char *start_mark, const char *end_mark, char *label, char *description)
{
	size_t label_length;
	const char *label_start_point, *end_mark_point;

	if (!SH_IsPrefix(start_mark, line)) {
		strcpy(label, "");
		strcpy(description, line);
		return(1);
	}

	label_start_point = line + strlen(start_mark);

	if ((end_mark_point = strstr(line, end_mark)) == NULL) {
		strcpy(label, label_start_point);
		strcpy(description, "");
		return(2);
	}

	label_length = end_mark_point - label_start_point;
	strncpy(label, label_start_point, label_length);
	strcpy(label + label_length, "\0");
	strcpy(description, end_mark_point + strlen(end_mark));

	return(0);
}

