/* ft_strrchr.c - Locate character in string (from end) */
/* Description: Returns a pointer to the last occurrence of the character c in the string s */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;

	length = ft_strlen(s);
	while (length > 0 && s[length] != (char)c)
		length--;
	if (s[length] == (char)c)
		return ((char *)&s[length]);
	return (NULL);
}
