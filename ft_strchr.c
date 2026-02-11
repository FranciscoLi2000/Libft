/* ft_strchr.c - Locate character in string */
/* Author: your_login */
/* Description: Returns a pointer to the first occurrence of the character c in the string s */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/* ft_strrchr.c - Locate character in string (from end) */
/* Author: your_login */
/* Description: Returns a pointer to the last occurrence of the character c in the string s */

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