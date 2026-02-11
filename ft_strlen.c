/* ft_strlen.c - Calculate string length */
/* Author: your_login */
/* Description: Calculates the length of the string s */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}