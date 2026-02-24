#include "ft_printf.h"

/*
 * ** Simple dispatcher for mandatory conversions:
 * ** c s p d i u x X %
 * */

static int	dispatch_conversion(char conv, va_list args)
{
	if (conv == 'c')
		return (ft_print_char((char)va_arg(args, int)));
	if (conv == 's')
		return (ft_print_str(va_arg(args, const char *)));
	if (conv == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (conv == 'd' || conv == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (conv == 'u')
		return (ft_print_uint(va_arg(args, unsigned int)));
	if (conv == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	if (conv == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	if (conv == '%')
		return (ft_print_percent());
	return (0);	/* unknown conversion: do nothing (should not happen in legal format) */
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		i;
	int		r;

	if (!format)
		return (-1);
	va_start(args, format);
	total = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			r = dispatch_conversion(format[i], args);
			if (r < 0)
			{
				va_end(args);
				return (-1);
			}
			total += r;
		}
		else
		{
			if (write(1, &format[i], 1) < 0)
			{
				va_end(args);
				return (-1);
			}
			total++;
		}
		i++;
	}
	va_end(args);
	return (total);
}
