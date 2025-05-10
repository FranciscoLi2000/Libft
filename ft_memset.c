#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	value;
	void		*original;

	ptr = (unsigned char *)str;
	value = (unsigned char)c;
	original = str;
	while (n-- > 0)
		*ptr++ = value;
	return (original);
}
