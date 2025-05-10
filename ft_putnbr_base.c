#include "libft.h"

static int	double_char(char *str)
{
	int	i;
	int	j;

	i = j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] != str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	print_nbr(int n, int base_value, char *symbols)
{
	long	nlong;

	nlong = n;
	if (nlong < 0)
	{
		nlong = -nlong;
		ft_putchar('-');
	}
	if (nlong >= base_value)
		print_nbr(nlong / base_value, base_value, symbols);
	ft_putchar(symbols[nlong % base_value]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_value;

	base_value = 0;
	while (base[base_value])
	{
		if (base[base_value] == '+' || base[base_value] == '-')
			return ;
		++base_value;
	}
	if (base_value < 2 || double_char(base))
		return ;
	print_nbr(nbr, base_value, base);
}
