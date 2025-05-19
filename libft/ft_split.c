/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:37:00 by yufli             #+#    #+#             */
/*   Updated: 2025/05/19 09:34:14 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s == c)
	{
		len++;
		s++;
	}
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
	int		count;
	int		i;
	int		len;

	count = 0;
	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
	{
		if (s[len++] != c && (len == 1 || s[len - 2] == c))
			count++;
	}
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = word_len(s, c);
			result[i] = ft_substr(s, 0, len);
		}
	}
	return (result);
}
