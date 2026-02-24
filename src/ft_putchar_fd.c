/* ft_putchar_fd.c - Put character to file descriptor */
/* Description: Outputs the character c to the given file descriptor */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
