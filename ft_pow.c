#include "libft.h"

int	ft_pow(int base, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (ft_pow(base, pow - 1) * base);
}
