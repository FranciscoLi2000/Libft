/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:37:00 by yufli             #+#    #+#             */
/*   Updated: 2025/06/04 03:51:55 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char c)
{
	return (c == ' ');
}

static int	word_count(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_separator(*str) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_separator(*str))
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*malloc_word(char *start)
{
	char	*word;
	int		len;

	len = 0;
	while (start[len] && !is_separator(start[len]))
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	len = 0;
	while (start[len] && !is_separator(start[len]))
	{
		word[len] = start[len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	result = (char **)malloc((word_count(str) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str && is_separator(*str))
			str++;
		if (*str)
		{
			result[i] = malloc_word(str);
			if (!result[i])
				return (NULL);
			i++;
			while (*str && !is_separator(*str))
				str++;
		}
	}
	result[i] = NULL;
	return (result);
}
