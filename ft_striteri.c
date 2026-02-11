/* ft_striteri.c - Iterate string with function */
/* Author: your_login */
/* Description: Applies the function f to each character of the string s, passing its index as first argument */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	length;
	size_t	i;

	if (s == NULL || f == NULL)
		return;
	length = ft_strlen(s);
	i = 0;
	while (i < length)
	{
		f(i, &s[i]);
		i++;
	}
}

/* ft_putchar_fd.c - Put character to file descriptor */
/* Author: your_login */
/* Description: Outputs the character c to the given file descriptor */

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