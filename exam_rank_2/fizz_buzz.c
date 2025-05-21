/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buzz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:45:02 by yufli             #+#    #+#             */
/*   Updated: 2025/05/21 15:45:05 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : fizzbuzz
 * Expected files   : fizzbuzz.c
 * Allowed functions: write */

/* Write a program that prints the numbers from 1 to 100, each separated by a newline.
 * If the number is a multiple of 3, it prints 'fizz' instead.
 * If the number is a multiple of 5, it prints 'buzz' instead.
 * If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead. */

/* Example:
 * $>./fizzbuzz
 * 1
 * 2
 * fizz
 * 4
 * buzz
 * fizz
 * 7
 * 8
 * fizz
 * buzz
 * 11
 * fizz
 * 13
 * 14
 * fizzbuzz
 * [...]
 * 97
 * 98
 * fizz
 * buzz
 * $> */

#include "exam.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr == INT_MIN)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
}
/*
int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0)
			ft_putstr("fizz\n");
		else if (i % 5 == 0)
			ft_putstr("buzz\n");
		else if (i % 3 == 0 && i % 5 == 0)
			ft_putstr("fizzbuzz\n");
		else
		{
			ft_putnbr(i);
			ft_putchar('\n');
		}
		i++;
	}
	return (0);
}*/
