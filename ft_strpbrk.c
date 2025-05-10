#include "libft.h"

char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (*s2 == '\0')
		return (NULL);
	while (*s1 != '\0')
	{
		temp = s2;
		while (*temp != '\0')
		{
			if (*s1 == *temp)
				return ((char *)s1);
			temp++;
		}
		s1++;
	}
	return (NULL);
}
