#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		value;

	p = (const unsigned char *)s;
	value = (unsigned char)c;
	while (n-- > 0)
	{
		if (*p == value)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
