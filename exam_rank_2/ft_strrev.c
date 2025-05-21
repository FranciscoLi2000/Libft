/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:25:02 by yufli             #+#    #+#             */
/*   Updated: 2025/05/21 17:31:41 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:
*/

#include "exam.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	j = 0;
	while (str[j])
		j++;
	j--;
	i = 0;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}
