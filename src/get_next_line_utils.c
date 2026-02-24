#include "get_next_line.h"

/* strlen */
size_t	ft_gnl_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* strchr: returns pointer to first occurrence or NULL */
char	*ft_gnl_strchr(const char *s, int c)
{
	size_t i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

/* join s1 + s2. frees s1. returns new allocated string or NULL */
char	*ft_gnl_strjoin(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	size_t	i;
	size_t	j;

	if (!s2)
		return (s1);
	len1 = ft_gnl_strlen(s1);
	len2 = ft_gnl_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	while (j < len2)
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

/* extract the line to return (including '\\n' if present) */
char	*ft_gnl_getline(const char *stash)
{
	size_t	i;
	size_t	len;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		len = i + 1;
	else
		len = i;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i++] = '\n';
	}
	line[i] = '\0';
	return (line);
}

/* remove the returned line from stash and return new stash (frees old stash) */
char	*ft_gnl_newstash(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}	/* skip the '\n' */
	i++;
	len = ft_gnl_strlen(stash + i);
	new = (char *)malloc(len + 1);
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}
