/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:38:25 by yufli             #+#    #+#             */
/*   Updated: 2025/05/22 21:32:47 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include "exam.h"

int     *ft_rrange(int start, int end)
{
	int	len;
	int	*arr;
	int	i;

	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		if (start < end)
			arr[i] = end--;
		else
			arr[i] = end++;
		i++;
	}
	return (arr);
}
