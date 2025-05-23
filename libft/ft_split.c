/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:37:00 by yufli             #+#    #+#             */
/*   Updated: 2025/05/23 21:03:41 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

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
