/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:31:00 by yufli             #+#    #+#             */
/*   Updated: 2025/06/11 20:23:56 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen_base(int value, int base)
{
	int	len;

	len = 0;
	if (value == 0)
		return (1);
	if (value < 0 && base == 10)
	{
		len++;
		value = -value;
	}
	while (value > 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		len;

	len = ft_numlen_base(value, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (value == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (value < 0 && base == 10)
	{
		str[0] = '-';
		value = -value;
	}
	while (value > 0)
	{
		str[--len] = "0123456789ABCDEF"[value % base];
		value /= base;
	}
	return (str);
}
