/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:37:00 by yufli             #+#    #+#             */
/*   Updated: 2025/05/19 12:13:23 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_all(char **res, int i)
{
	while (--i >= 0)
		free(res[i]);
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		word_length;
	int		word_count;

	i = 0;
	word_count = 0;
	if (!s)
		return (NULL);
	j = 0;
	while (s[j])
	{
		if (s[j] != c && (j == 0 || s[j - 1] == c))
			word_count++;
		j++;
	}
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word_length = word_len(s, c);
			result[i] = ft_substr(s, 0, word_length);
			if (!result[i++])
			{
				free_all(result, i);
				return (NULL);
			}
			s += word_length;
		}
	}
	result[i] = NULL;
	return (result);
}
