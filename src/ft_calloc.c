/* ft_calloc.c - Memory allocation with zeroing */
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
