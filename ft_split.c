/* La más dura, pero con pasos claros es fácil. */

#include "libft.h"

/* contar palabras */
static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

/* copiar palabra */
static char	*word_dup(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

/* función principal */
char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[i++] = word_dup(s, c);
			while (*s && *s != c)
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}
/* Forma de recordarlo: contar → reservar → extraer → NULL final */

