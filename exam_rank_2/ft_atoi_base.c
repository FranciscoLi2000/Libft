/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:21:58 by yufli             #+#    #+#             */
/*   Updated: 2025/05/22 19:36:38 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:
*/

#include "exam.h"

// 辅助函数：将字符转换为对应的数字值
// 这个函数封装了字符到数值的转换逻辑，让主函数更清晰
int	char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');           // '0'->0, '1'->1, ..., '9'->9
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);      // 'a'->10, 'b'->11, ..., 'f'->15
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);      // 'A'->10, 'B'->11, ..., 'F'->15
	else
		return (-1);                // 无效字符返回-1
}

// 辅助函数：检查进制是否有效
// 这个函数确保我们不会处理无效的进制参数
int	is_valid_base(int base)
{
	return (base >= 2 && base <= 16);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	num;
	int	digit_value;    // 存储当前字符对应的数字值
	
	// 首先检查进制是否有效，如果无效直接返回0
	// 这样我们就不需要在每次循环中都检查了
	if (!is_valid_base(str_base))
		return (0);
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	// 主循环：处理所有有效的进制字符了
	while (str[i])  // 只要还有字符就继续处理
	{
		// 将当前字符转换为数字值
		digit_value = char_to_digit(str[i]);
		// 检查字符是否有效且在当前进制范围内
		if (digit_value == -1 || digit_value >= str_base)
			break ;  // 遇到无效字符或超出进制范围的字符就停止
		// 执行进制转换的核心计算
		// 这里使用了Horner方法：将之前的结果乘以基数，加上当前位的值
		num = num * str_base + digit_value;
		i++;
	}
	return (sign * num);
}

/*
 * 让我们通过几个例子来理解这个改进版本：
 * 
 * 例1: ft_atoi_base("1A3", 16)
 *   - 跳过空白字符：无
 *   - 处理符号：默认为正
 *   - 处理'1'：digit_value = 1, num = 0*16 + 1 = 1
 *   - 处理'A'：digit_value = 10, num = 1*16 + 10 = 26  
 *   - 处理'3'：digit_value = 3, num = 26*16 + 3 = 419
 *   - 返回：419
 * 
 * 例2: ft_atoi_base("77", 8)  
 *   - 处理第一个'7'：digit_value = 7, num = 0*8 + 7 = 7
 *   - 处理第二个'7'：digit_value = 7, num = 7*8 + 7 = 63
 *   - 返回：63
 * 
 * 例3: ft_atoi_base("789", 8)
 *   - 处理'7'：digit_value = 7, num = 0*8 + 7 = 7
 *   - 遇到'8'：digit_value = 8, 但8 >= 8(base)，所以停止
 *   - 返回：7（只转换了有效的部分）
 */
