/* ft_strlcpy.c - Copy string to buffer */
/* Description: Copies up to destsize characters from the string src to dst */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(src);
	if (destsize == 0)
		return (length);
	i = 0;
	while (i < destsize - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}
