/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:34:41 by yufli             #+#    #+#             */
/*   Updated: 2025/05/21 17:52:52 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int	i;
	int	j;
	int	k;
	int	used[256];

	k = 0;
	while (k < 256)
	{
		used[k] = 0;
		k++;
	}
	i = -1;
	while (s1[++i])
	{
		j = -1;
		while (s2[++j])
		{
			if (s1[i] == s2[j] && used[(unsigned char)s1[i]] == 0)
			{
				write(1, &s1[i], 1);
				used[(unsigned char)s1[i]] = 1;
				break ;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		inter(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
