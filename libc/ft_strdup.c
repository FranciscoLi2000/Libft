#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		i;
	int		size;
	int		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	if (s == 0)
		return (0);
	size = len + 1;
	dst = malloc(size * sizeof(char));
	if (dst == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
