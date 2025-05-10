#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	const char	*p;
	size_t		count;

	count = 0;
	while (*s)
	{
		p = reject;
		while (*p)
		{
			if (*s == *p)
				return (count);
			p++;
		}
		count++;
		s++;
	}
	return (count);
}
