#include "ft_printf.h"

/*
 * ** print pointer: (nil) for NULL, else 0x + hex lowercase
 * */
static int	puthex_recursive_unsigned(unsigned long n, int uppercase)
{
	char	c;
	int		cnt;

	cnt = 0;
	if (n >= 16)
	{
		cnt = puthex_recursive_unsigned(n / 16, uppercase);
		if (cnt < 0)
		return (-1);
	}
	if (n % 16 < 10)
		c = '0' + (n % 16);
	else
	{
		if (uppercase)
			c = 'A' + (n % 16 - 10);
		else
			c = 'a' + (n % 16 - 10);
	}
	if (write(1, &c, 1) < 0)
		return (-1);
	return (cnt + 1);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	addr;
	int			cnt;

	if (!ptr)
	{
		if (write(1, "(nil)", 5) < 0)
			return (-1);
		return (5);
	}
	addr = (unsigned long)ptr;	/* write "0x" prefix */
	if (write(1, "0x", 2) < 0)
		return (-1);
	cnt = 2;
	cnt += puthex_recursive_unsigned(addr, 0);
	return (cnt);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	return (puthex_recursive_unsigned((unsigned long)n, uppercase));
}
