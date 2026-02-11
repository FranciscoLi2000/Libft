/* ft_printf.c - Custom printf implementation */
/* Author: your_login */
/* Description: Custom printf implementation supporting basic format specifiers */

#include "ft_printf.h"
#include "libft.h"
#include "ft_putnbr_fd.h"
#include "ft_putunbr_fd.h"
#include "ft_puthex_fd.h"

/**
 * ft_format_specifier - Handle format specifier
 * @ptr: Pointer to format character
 * @args: Variable arguments list
 *
 * Return: Number of characters written for this specifier
 */
static int ft_format_specifier(const char *ptr, va_list args)
{
	int written;
	int num;
	unsigned int u_num;
	void *ptr_arg;
	char *str_arg;
	char char_arg;

	written = 0;
	
	switch (*ptr)
	{
		case 'c':
			char_arg = va_arg(args, int);
			ft_putchar_fd(char_arg, 1);
			written = 1;
			break;
			
		case 's':
			str_arg = va_arg(args, char *);
			if (str_arg)
				written = ft_strlen(str_arg);
			else
			{
				ft_putstr_fd("(null)", 1);
				written = 6;
			}
			break;
			
		case 'p':
			ptr_arg = va_arg(args, void *);
			ft_putstr_fd("0x", 1);
			written = 2;
			if (ptr_arg == NULL)
			{
				ft_putstr_fd("nil", 1);
				written += 3;
			}
			else
			{
				ft_puthex_fd((unsigned long)ptr_arg, 1, 0);
				// Calculate the number of digits in hexadecimal
				int temp = (unsigned long)ptr_arg;
				while (temp > 0)
				{
					temp /= 16;
					written++;
				}
			}
			break;
			
		case 'd':
		case 'i':
			num = va_arg(args, int);
			{
				int neg = num < 0;
				if (neg)
				{
					ft_putchar_fd('-', 1);
					written++;
					num = -num;
				}
				int temp = num;
				while (temp > 0)
				{
					temp /= 10;
					written++;
				}
				if (num == 0)
					written = neg ? 1 : 1;
				ft_putnbr_fd(neg ? -num : num, 1);
			}
			break;
			
		case 'u':
			u_num = va_arg(args, unsigned int);
			{
				int temp = u_num;
				while (temp > 0)
				{
					temp /= 10;
					written++;
				}
				if (u_num == 0)
					written = 1;
			}
			ft_putunbr_fd(u_num, 1);
			break;
			
		case 'x':
			u_num = va_arg(args, unsigned int);
			{
				int temp = u_num;
				while (temp > 0)
				{
					temp /= 16;
					written++;
				}
				if (u_num == 0)
					written = 1;
			}
			ft_puthex_fd(u_num, 1, 0);
			break;
			
		case 'X':
			u_num = va_arg(args, unsigned int);
			{
				int temp = u_num;
				while (temp > 0)
				{
					temp /= 16;
					written++;
				}
				if (u_num == 0)
					written = 1;
			}
			ft_puthex_fd(u_num, 1, 1);
			break;
			
		case '%':
			ft_putchar_fd('%', 1);
			written = 1;
			break;
			
		default:
			ft_putchar_fd('%', 1);
			ft_putchar_fd(*ptr, 1);
			written = 2;
			break;
	}
	
	return (written);
}

/**
 * ft_printf - Custom printf implementation
 * @format: Format string
 * @...: Variable arguments
 *
 * Return: Number of characters written
 *
 * Supported format specifiers: %c, %s, %p, %d, %i, %u, %x, %X, %%
 */
int ft_printf(const char *format, ...)
{
	va_list args;
	int written;
	const char *ptr;

	va_start(args, format);
	written = 0;
	ptr = format;
	
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (!*ptr)
				break;
			written += ft_format_specifier(ptr, args);
			ptr++;
		}
		else
		{
			ft_putchar_fd(*ptr, 1);
			written++;
			ptr++;
		}
	}
	
	va_end(args);
	return (written);
}