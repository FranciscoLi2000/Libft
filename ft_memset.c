/* ft_memset.c - Fill memory with a constant byte */
/* Author: your_login */
/* Description: Fills the first n bytes of the memory area pointed to by s with the constant byte c */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* ft_bzero.c - Zero out a byte string */
/* Author: your_login */
/* Description: Erases the data in the n bytes of the memory area pointed to by s by writing zeros */

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}