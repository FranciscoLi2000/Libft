/* ft_tolower.c - Convert to lowercase */
/* Author: your_login */
/* Description: Converts an uppercase letter to its corresponding lowercase letter */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}