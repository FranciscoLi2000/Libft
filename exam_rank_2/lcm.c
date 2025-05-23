/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:39:09 by yufli             #+#    #+#             */
/*   Updated: 2025/05/22 23:27:19 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:
*/

#include "exam.h"

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	g;

	if (a == 0 || b == 0)
		return (0);
	if (a < b)
		g = b;
	else
		g = a;
	while (1)
	{
		if (g % a == 0 && g % b == 0)
			return (g);
		g++;
	}
}

int	main(int ac, char **av)
{
	unsigned int	m;

	if (ac == 3)
	{
		m = lcm(atoi(av[1]), atoi(av[2]));
		printf("LCM: %u", m);
	}
	printf("\n");
	return (0);
}
