#include "libft.h"

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	src_len;
//	unsigned int	dst_len;
	unsigned int	i;
	unsigned int	j;

	src_len = ft_strlen(src);
//	dst_len = ft_strlen(dst);
	i = 0;
	j = 0;
	while (++i < size && *dst)
		dst++;
	if (i < size)
		return (i + src_len);
	while (src[j])
	{
		if (j < size - i - 1)
			*dst++ = src[j];
		j++;
	}
	*dst = '\0';
	return (i + j);
}
