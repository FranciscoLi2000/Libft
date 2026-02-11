/* ft_isalpha.c - Check if character is alphabetic */
/* Author: your_login */
/* Description: Returns 1 if c is alphabetic, 0 otherwise */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}