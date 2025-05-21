/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:45:13 by yufli             #+#    #+#             */
/*   Updated: 2025/05/21 15:45:16 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : ft_strcpy
 * Expected files   : ft_strcpy.c
 * Allowed functions: - */

/* Reproduce the behavior of the function strcpy (man strcpy).
 * Your function must be declared as follows: */

#include "exam.h"

char    *ft_strcpy(char *s1, char *s2)
{
	int	i;

	while (s2[i])
	{
		s1[i] != s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
