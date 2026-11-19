#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct s_instruct
{
	int		type;
	char	*line;
	struct	s_intruct *next;
}	t_instruct;

typedef struct s_files
{
	char *folder;
	struct s_files *next;
	int		to_print;
}	t_files;

#endif
