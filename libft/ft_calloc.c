/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:34:27 by yufli             #+#    #+#             */
/*   Updated: 2025/06/14 16:39:59 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void	*ptr;

	// 防止整数溢出：如果 nmemb * size 超过 size_t 范围
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);

	// 推荐调用自己实现的 ft_bzero
	ft_bzero(ptr, nmemb * size);

	/* 如果不允许调用 ft_bzero，也可以手动写循环
	size_t i = 0;
	while (i < nmemb * size)
		((unsigned char *)ptr)[i++] = 0; */

	return (ptr);
}
