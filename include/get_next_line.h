/* get_next_line.h - Header file for get_next_line */
/* Author: your_login */
/* Description: Contains get_next_line function prototype and supporting definitions */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

/* Main function */
char	*get_next_line(int fd);

#endif