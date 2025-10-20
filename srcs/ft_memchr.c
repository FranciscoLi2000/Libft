#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t count)
{
	const unsigned char	*p;
	unsigned char		byte;
	size_t			i;

	p = (const unsigned char *)ptr;
	byte = (unsigned char)value;
	i = 0;
	while (i < count)
	{
		if (p[i] == byte)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
