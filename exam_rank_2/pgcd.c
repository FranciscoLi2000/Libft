/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:15:08 by yufli             #+#    #+#             */
/*   Updated: 2025/05/23 00:29:05 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

void	pgcd(int n1, int n2)
{
	if (n1 <= 0 || n2 <= 0)
		return ;
	while (n1 != n2)
	{
		if (n1 > n2)
			n1 = n1 - n2;
		else
			n2 = n2 - n1;
	}
	printf("%d", n1);
}

int	main(int argc, char **argv)
{
	int	n1;
	int	n2;

	if (argc == 3)
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[2]);
		pgcd(n1, n2);
	}
	printf("\n");
	return (0);
}
