/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:00:26 by yufli             #+#    #+#             */
/*   Updated: 2025/06/14 17:01:22 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char		*ptr;
	unsigned char		uc;

	ptr = s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = uc;
		i++;
	}
	return (s);
}
