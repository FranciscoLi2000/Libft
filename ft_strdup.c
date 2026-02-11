/* ft_strdup.c - Duplicate string */
/* Author: your_login */
/* Description: Returns a pointer to a new string which is a duplicate of the string s */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*duplicate;

	length = ft_strlen(s);
	duplicate = malloc(length + 1);
	if (duplicate == NULL)
		return (NULL);
	ft_strlcpy(duplicate, s, length + 1);
	return (duplicate);
}