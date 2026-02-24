#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);

/*
 *  * Printers (mandatory conversions)
 *   */
int		ft_print_char(char c);
int		ft_print_str(const char *s);
int		ft_print_ptr(void *ptr);
int		ft_print_int(int n);
int		ft_print_uint(unsigned int n);
int		ft_print_hex(unsigned int n, int uppercase);
int		ft_print_percent(void);

#endif /* FT_PRINTF_H */
