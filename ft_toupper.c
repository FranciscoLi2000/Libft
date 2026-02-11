/* ft_toupper.c - Convert to uppercase */
/* Author: your_login */
/* Description: Converts a lowercase letter to its corresponding uppercase letter */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/* ft_tolower.c - Convert to lowercase */
/* Author: your_login */
/* Description: Converts an uppercase letter to its corresponding lowercase letter */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}