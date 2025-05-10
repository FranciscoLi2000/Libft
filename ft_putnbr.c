#include "libft.h"

void	ft_putnbr(int nbr)
{
	long	nbl;
	char	c[10];
	short	i;

	nbl = nbr;
	i = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nbl < 0)
	{
		nbl *= -1;
		write(1, "-", 1);
	}
	while (nbl % 10)
	{
		c[i++] = (nbl % 10) + 48;
		nbl /= 10;
	}
	while (i >= 0)
		write(1, &c[--i], 1);
}
