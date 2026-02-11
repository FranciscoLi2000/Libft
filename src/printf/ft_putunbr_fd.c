/* ft_putunbr_fd.c - Put unsigned number to file descriptor */
/* Author: your_login */
/* Description: Outputs the unsigned integer n to the given file descriptor */

#include "libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd('0' + n, fd);
	}
}