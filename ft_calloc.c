/* ft_calloc.c - Memory allocation with zeroing */
/* Author: your_login */
/* Description: Allocates memory for an array of count elements of size bytes each and returns a pointer to the allocated memory */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/* ft_strdup.c - Duplicate string */
/* Author: your_login */
/* Description: Returns a pointer to a new string which is a duplicate of the string s */

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