#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(str) + 1;
	new_str = (char *)malloc(len * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	return (ft_memcpy(new_str, str, len));
}
