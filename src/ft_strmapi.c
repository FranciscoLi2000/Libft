/* ft_strmapi.c - Map string with function */
/* Description: Applies the function f to each character of the string s to create a new string */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	length;
	size_t	i;
	char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	length = ft_strlen(s);
	result = malloc(length + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[length] = '\0';
	return (result);
}
