#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_word_dup(char const *s, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_split(char **split, size_t count)
{
	while (count > 0)
	{
		count--;
		free(split[count]);
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;
	size_t	i;
	size_t	start;
	size_t	len;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	start = 0;
	while (s[start])
	{
		while (s[start] == c)
			start++;
		if (!s[start])
			break ;
		len = 0;
		while (s[start + len] && s[start + len] != c)
			len++;
		split[i] = ft_word_dup(s + start, len);
		if (!split[i])
		{
			ft_free_split(split, i);
			return (NULL);
		}
		i++;
		start += len;
	}
	split[i] = NULL;
	return (split);
}
