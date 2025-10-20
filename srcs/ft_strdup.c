#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char));
	if (!res)
		return (NULL);
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
