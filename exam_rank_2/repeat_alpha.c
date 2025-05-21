/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:45:30 by yufli             #+#    #+#             */
/*   Updated: 2025/05/21 15:45:32 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:
$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int	ft_islower(int c)
{
	if (c >= 97 && c <= 123)
		return (1);
	return (0);
}

int	ft_isupper(int c)
{
	if (c >= 65 && c <= 91)
		return (1);
	return (0);
}

void	repeat_alpha(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]))
		{
			j = 0;
			while (j < str[i] - 64)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		else if (ft_islower(str[i]))
		{
			j = 0;
			while (j < str[i] - 96)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		repeat_alpha(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
