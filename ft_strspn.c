#include "libft.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t		count;
	const char	*p;
	int			found;

	count = 0;
	while (*s)
	{
		found = 0;
		p = accept;
		while (*p)
		{
			if (*s == *p)
			{
				found = 1;
				break ;
			}
			p++;
		}
		if (!found)
			return (count);
		s++;
		count++;
	}
	return (count);
}
