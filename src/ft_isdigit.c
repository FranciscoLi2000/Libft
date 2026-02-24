/* ft_isdigit.c - Check if character is digit */
/* Description: Returns 1 if c is digit, 0 otherwise */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
