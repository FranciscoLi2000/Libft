/* ft_putstr_fd.c - Put string to file descriptor */
/* Description: Outputs the string s to the given file descriptor */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}
