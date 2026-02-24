/* ft_isalnum.c - Check if character is alphanumeric */
/* Description: Returns 1 if c is alphabetic or digit, 0 otherwise */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
