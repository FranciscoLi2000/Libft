#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	void			*original;

	d = (unsigned char *)str1;
	s = (const unsigned char *)str2;
	original = str1;
	while (n-- > 0)
		*d++ = *s++;
	return (original);
}
