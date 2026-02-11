/* ft_memchr.c - Find character in memory */
/* Author: your_login */
/* Description: Scans the first n bytes of the memory area pointed to by s for the first instance of c */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}

/* ft_memcmp.c - Compare memory areas */
/* Author: your_login */
/* Description: Compares the first n bytes of the memory areas s1 and s2 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}