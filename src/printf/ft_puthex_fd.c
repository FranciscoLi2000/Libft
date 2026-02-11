/* ft_puthex_fd.c - Put hexadecimal number to file descriptor */
/* Author: your_login */
/* Description: Outputs the hexadecimal representation of n to the given file descriptor */

#include "libft.h"

void	ft_puthex_fd(unsigned long n, int fd, int upper)
{
	if (n >= 16)
	{
		ft_puthex_fd(n / 16, fd, upper);
		ft_puthex_fd(n % 16, fd, upper);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd('0' + n, fd);
		else if (upper)
			ft_putchar_fd('A' + n - 10, fd);
		else
			ft_putchar_fd('a' + n - 10, fd);
	}
}