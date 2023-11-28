/*
 * libshun.h		by Shun Morimura
 */
#ifndef LIBSHUN_H
#define LIBSHUN_H

/*
 * definitions of constant number
 */
#define COM_OPT_ARG_SIZE	255

/*
 * definition of boolean type
 */
typedef enum {
	FALSE,
	TRUE
} SH_bool;

/*
 * definitions of macro
 */
#define SH_IsSjisKanji(c) ((0x81 <= (unsigned char)(c&0xff) && (unsigned char)(c&0xff) <= 0x9f) \
                        || (0xe0 <= (unsigned char)(c&0xff) && (unsigned char)(c&0xff) <= 0xfc))

/*
 * declarations of function prototype
 */
SH_bool	SH_IsPrefix(const char *prefix, const char *buffer);
SH_bool	SH_IsFile(const char *filename);
char	SH_GetComParameter(const char *com_param, char *com_opt_arg, const char *special_opt_letters);
char	*SH_CutNewLineByte(char *line);
char	*SH_ExpandTabToSpaces(int tab_width, const char *line, char *buffer);
char	*SH_GetCommandPath(const char *argv0, char *com_path);
int		SH_ErrorExit(const char *fmt, ...);
int		SH_GetLabelAndDescription(const char *line, const char *start_mark, const char *end_mark, char *label, char *description);
char	*SH_StringCopy(char *dst, const char *src, size_t size);

#endif	/* LIBSHUN_H */

