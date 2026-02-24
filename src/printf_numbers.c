#include "ft_printf.h"

/*
 * ** Integers
 * */
static int	putunbr_recursive(unsigned long n)
{
	char	c;
	int		cnt;

	cnt = 0;
	if (n >= 10)
	{
		cnt = putunbr_recursive(n / 10);
		if (cnt < 0)
			return (-1);
	}
	c = '0' + (n % 10);
	if (write(1, &c, 1) < 0)
		return (-1);
	return (cnt + 1);
}

int	ft_print_int(int n)
{
	unsigned long	val;
	int			cnt;

	cnt = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		cnt++;
		val = (unsigned long)(-(long)n);
	}
	else
		val = (unsigned long)n;
	cnt += putunbr_recursive(val);
	return (cnt);
}

int	ft_print_uint(unsigned int n)
{
	return (putunbr_recursive((unsigned long)n));
}
