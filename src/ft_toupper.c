/* ft_toupper.c - Convert to uppercase */
/* Description: Converts a lowercase letter to its corresponding uppercase letter */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
