/* ft_strtrim.c - Trim string */
/* Description: Allocates and returns a copy of s1 with the characters specified in set removed from the beginning and the end */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	length;
	char	*trim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	length = ft_strlen(s1);
	start = 0;
	while (start < length && ft_strchr(set, s1[start]) != NULL)
		start++;
	if (start == length)
		return (ft_strdup(""));
	end = length;
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	trim = ft_substr(s1, start, end - start);
	return (trim);
}
