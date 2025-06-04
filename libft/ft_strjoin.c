/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:37:36 by yufli             #+#    #+#             */
/*   Updated: 2025/06/04 03:22:05 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strs_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += (size - 1) * ft_strlen(sep);
	return (len);
}

static char	*ft_strcpy_and_advance(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	char	*tmp;
	int		i;

	if (size == 0)
		return (ft_strdup(""));
	joined = (char *)malloc(ft_strs_len(size, strs, sep) + 1);
	if (!joined)
		return (NULL);
	tmp = joined;
	i = 0;
	while (i < size)
	{
		tmp = ft_strcpy_and_advance(tmp, strs[i]);
		if (i++ < size - 1)
			tmp = ft_strcpy_and_advance(tmp, sep);
	}
	*tmp = '\0';
	return (joined);
}
