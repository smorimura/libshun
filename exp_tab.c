/*
 * exp_tab.c		by Shun Morimura
 */
char *SH_ExpandTabToSpaces(int tab_width, const char *line, char *buffer)
{
	int i, j;
	int num_char = 0;
	int spaces;

	for (i = 0; line[i] != '\0'; ++i) {
		if (line[i] == '\t') {
			spaces = tab_width - num_char % tab_width;
			for (j = 0; j < spaces; ++j) {
				buffer[num_char] = ' ';
				++num_char;
			}
		} else {
			buffer[num_char] = line[i];
			++num_char;
		}
	}

	buffer[num_char] = '\0';

	return(buffer);
}

