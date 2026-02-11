/* ft_putendl_fd.c - Put string with newline to file descriptor */
/* Author: your_login */
/* Description: Outputs the string s to the given file descriptor followed by a newline */

#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	if (s != NULL)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

/* ft_putnbr_fd.c - Put number to file descriptor */
/* Author: your_login */
/* Description: Outputs the integer n to the given file descriptor */

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd('0' + n, fd);
	}
}