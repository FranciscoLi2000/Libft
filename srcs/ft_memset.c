#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t count)
{
	unsigned char	*p;
	unsigned char	byte;
	size_t		i;

	p = (unsigned char*)ptr;
	byte = (unsigned char)value;
	i = 0;
	while (i < count)
	{
		p[i] = byte;
		i++;
	}
	return (ptr);
}
