#include "ft_printf.h"

/*
 * ** Small helpers used by printers
 * */
static int	ft_putchar_count(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	ft_print_char(char c)
{
	return (ft_putchar_count(c));
}

int	ft_print_percent(void)
{
	return (ft_putchar_count('%'));
}

int	ft_print_str(const char *s)
{
	size_t	len;

	if (!s)
	{	/* libc printf prints (null) for %s with NULL */
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	len = 0;
	while (s[len])
		len++;
	if (len > 0)
	{
		if (write(1, s, len) < 0)
			return (-1);
	}
	return ((int)len);
}
