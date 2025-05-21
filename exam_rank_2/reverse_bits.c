/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:32:07 by yufli             #+#    #+#             */
/*   Updated: 2025/05/21 18:41:22 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
     ||
     \/
 0110  0100 */

#include "exam.h"

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int			i;

	result = 0;
	i = 8;
	while (i--)
	{
		result = (result << 1) | (octet & 1);
	}
	return (result);
}
