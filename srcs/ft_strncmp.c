#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
