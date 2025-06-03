#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	copy = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
