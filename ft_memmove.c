#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	void			*original;

	d = (unsigned char *)str1;
	s = (const unsigned char *)str2;
	original = str1;
	if (d > s && d < s + n)
	{
		d += n - 1;
		s += n - 1;
		while (n-- > 0)
			*d-- = *s--;
	}
	else
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	return (original);
}
