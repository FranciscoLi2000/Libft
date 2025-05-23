/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:42:52 by yufli             #+#    #+#             */
/*   Updated: 2025/05/22 17:15:58 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>

void	wdmatch(char *s1, char *s2)
{
	int	i;
	int	len;

	len = 0;
	while (s1[len])
		len++;
	i = 0;
	while (i < len && *s2)
	{
		if (s1[i] == *s2++)
			i++;
	}
	if (i == len)
		write(1, s1, len);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		wdmatch(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
