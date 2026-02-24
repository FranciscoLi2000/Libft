/* ft_putendl_fd.c - Put string with newline to file descriptor */
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
