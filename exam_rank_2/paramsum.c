/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:29:13 by yufli             #+#    #+#             */
/*   Updated: 2025/05/23 00:14:33 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/

#include "exam.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	i = 1;
	while (i < argc)
		i++;
	ft_putnbr(i - 1);
	ft_putchar('\n');
	return (0);
}
