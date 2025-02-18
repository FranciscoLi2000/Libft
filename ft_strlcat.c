#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dest_len = 0;
	while (dst[dest_len] != '\0' && dest_len < dstsize)
		dest_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len >= dstsize)
		return (dstsize + src_len);
	while (src[i] != '\0' && (dest_len + i + 1) < dstsize)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
