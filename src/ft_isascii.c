/* ft_isascii.c - Check if character is ASCII */
/* Description: Returns 1 if c is ASCII, 0 otherwise */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
