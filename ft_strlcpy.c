#include "libft.h"

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	int	len;

	len = 0;
	while (*(src + len) && --size)
		*dst++ = *(src + len++);
	*dst = '\0';
	while (*(src + len))
		++len;
	return (len);
}
