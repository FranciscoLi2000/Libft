/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:44:07 by yufli             #+#    #+#             */
/*   Updated: 2025/05/22 17:37:52 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$> */

#include <unistd.h>

void	ft_union(char *s1, char *s2)
{
	int	seen[256];
	int	i;
	int	k;

	k = 0;
	while (k < 256)
	{
		seen[k] = 0;
		k++;
	}
	i = 0;
	while (s1[i])
	{
		if (seen[(unsigned char)s1[i]] == 0)
		{
			write(1, &s1[i], 1);
			seen[(unsigned char)s1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (seen[(unsigned char)s2[i]] == 0)
		{
			write(1, &s2[i], 1);
			seen[(unsigned char)s2[i]] = 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
