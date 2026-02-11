/* ft_strjoin.c - Join strings */
/* Author: your_login */
/* Description: Allocates and returns a new string, which is the result of the concatenation of s1 and s2 */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	length1;
	size_t	length2;
	char	*join;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	length1 = ft_strlen(s1);
	length2 = ft_strlen(s2);
	join = malloc(length1 + length2 + 1);
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, length1 + 1);
	ft_strlcat(join, s2, length1 + length2 + 1);
	return (join);
}

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