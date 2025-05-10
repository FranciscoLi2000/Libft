#include "libft.h"

int	ft_atoi(char *str)
{
	short	parity;
	int	number;

	parity = number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			parity++;
		++str;
	}
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		++str;
	}
	if (parity % 2 == 0)
		return (number);
	return (-number);
}
