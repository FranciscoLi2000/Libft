/* ft_split.c - Split string */
/* Author: your_login */
/* Description: Allocates and returns an array of strings obtained by splitting s using the character c as a delimiter */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	length;
	char	**result;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		start = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		length = j - start;
		result[i] = ft_substr(s, start, length);
		if (result[i] == NULL)
		{
			while (i > 0)
			 free(result[--i]);
		 free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}