/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:36:03 by yufli             #+#    #+#             */
/*   Updated: 2025/05/22 22:26:27 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
*/

#include <unistd.h>

void	hidenp(char *s1, char *s2)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (s1[i] && s2[j])  // 当两个字符串都没到末尾时继续
	{
		if (s2[j] == s1[i])  // 找到匹配字符
			i++;          // 移动第一个字符串的指针
		j++;                  // 总是移动第二个字符串的指针
	}
	// 关键：判断第一个字符串是否完全被找到
	if (s1[i] == '\0')       // 如果第一个字符串已经遍历完
		write(1, "1", 1);    // 输出 1
	else
		write(1, "0", 1);    // 否则输出 0
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		hidenp(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
