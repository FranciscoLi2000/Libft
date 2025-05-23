/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:31:02 by yufli             #+#    #+#             */
/*   Updated: 2025/05/23 01:38:50 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include "libft.h"
#include <unistd.h>

// 将数字转换为对应的16进制字符（小写）
char	digit_to_hex(int digit)
{
	if (digit < 10)
		return ('0' + digit);
	else
		return ('a' + digit - 10);
}

// 将10进制数转换为16进制字符串
void	print_hex(int num)
{
	char	hex_digits[20];  // 足够存储32位整数的16进制表示
	int		i;

	if (num == 0)  // 特殊情况：数字为0
	{
		write(1, "0", 1);
		return ;
	}
	i = 0;
	while (num > 0)  // 从低位到高位提取每一位
	{
		hex_digits[i] = digit_to_hex(num % 16);  // 取余数得到当前位
		num = num / 16;  // 整除16得到下一位
		i++;
	}
	// 因为我们是从低位到高位存储的，所以需要倒序输出
	while (i > 0)
	{
		i--;
		write(1, &hex_digits[i], 1);
	}
}

int	main(int argc, char **argv)
{
	int	num;

	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		print_hex(num);
	}
	write(1, "\n", 1);
	return (0);
}
