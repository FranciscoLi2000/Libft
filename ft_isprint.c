/* ft_isprint.c - Check if character is printable */
/* Author: your_login */
/* Description: Returns 1 if c is printable, 0 otherwise */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}