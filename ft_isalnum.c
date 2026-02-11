/* ft_isalnum.c - Check if character is alphanumeric */
/* Author: your_login */
/* Description: Returns 1 if c is alphabetic or digit, 0 otherwise */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/* ft_isascii.c - Check if character is ASCII */
/* Author: your_login */
/* Description: Returns 1 if c is ASCII, 0 otherwise */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* ft_isprint.c - Check if character is printable */
/* Author: your_login */
/* Description: Returns 1 if c is printable, 0 otherwise */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}