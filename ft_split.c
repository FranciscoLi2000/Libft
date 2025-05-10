#include "libft.h"

static size_t	count_tokens(const char *str, char separator)
{
	size_t	tokens;
	bool	inside_tokens;

	tokens = 0;
	while (*str)
	{
		inside_tokens = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_tokens)
			{
				++tokens;
				inside_tokens = true;
			}
			++str;
		}
	}
	return (tokens);
}

static int	safe_malloc(char **strs, int position, size_t buffer)
{
	int	i;

	i = 0;
	strs[position] = malloc(buffer);
	if (!strs[position])
	{
		while (i < position)
			free(strs[i++]);
		free(strs);
		return (1);
	}
	return (0);
}

static size_t	fill(char **strs, const char *word, char separator)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*word)
	{
		len = 0;
		while (*word == separator && *word)
			++word;
		while (*word != separator && *word)
		{
			++len;
			++word;
		}
		if (len)
		{
			if (safe_malloc(strs, i, len + 1))
				return (1);
		}
		ft_strlcpy(strs[i], (char *)word - len, len + 1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**words;

	tokens = 0;
	tokens = count_tokens(s, c);
	words = malloc((tokens + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	words[tokens] = NULL;
	if (fill(words, s, c) == 1)
		return (NULL);
	return (words);
}
