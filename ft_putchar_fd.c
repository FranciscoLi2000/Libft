/* ft_putchar_fd.c - Put character to file descriptor */
/* Author: your_login */
/* Description: Outputs the character c to the given file descriptor */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* ft_putstr_fd.c - Put string to file descriptor */
/* Author: your_login */
/* Description: Outputs the string s to the given file descriptor */

void	ft_putstr_fd(const char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}