/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:21:12 by yufli             #+#    #+#             */
/*   Updated: 2025/05/23 21:00:31 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

void	find_prime_factors(int nb)
{
	int	i;
	int	first;

	first = 1;
	i = 2;
	while (i * i <= nb)
	{
		while (nb % i == 0)
		{
			if (!first)
				printf("*");
			printf("%d", i);
			first = 0;
			nb = nb / i;
		}
		i++;
	}
	if (nb > 1)
	{
		if (!first)
			printf("*");
		printf("%d", nb);
	}
}

int	main(int argc, char **argv)
{
	int	n;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	n = atoi(argv[1]);
	if (n == 1)
	{
		printf("1\n");
		return (0);
	}
	find_prime_factors(n);
	printf("\n");
	return (0);
}
