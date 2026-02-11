/* ft_strlcat.c - Append string to buffer */
/* Author: your_login */
/* Description: Appends the string src to the end of dst. It will append at most destsize - strlen(dst) - 1 characters */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (destsize <= dest_len)
		return (src_len + destsize);
	i = 0;
	while (src[i] != '\0' && dest_len + i < destsize - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}