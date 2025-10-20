#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t count)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t			i;

	p1 = (const unsigned char *)ptr1;
	p2 = (const unsigned char *)ptr2;
	i = 0;
	while (i < count)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
