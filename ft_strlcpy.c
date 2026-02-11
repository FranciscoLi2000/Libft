/* ft_strlcpy.c - Copy string to buffer */
/* Author: your_login */
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

/* ft_strlcat.c - Append string to buffer */
/* Author: your_login */
/* Description: Appends the string src to the end of dst. It will append at most destsize - strlen(dst) - 1 characters */

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