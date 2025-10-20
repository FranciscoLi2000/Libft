#include "libft.h"

static int	num_len(int nb)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		i;
	int		len;

	num = n;
	len = num_len(n);
	res = (char *)malloc((sizeof(char) * (len + 1)));
	if (!res)
		return (NULL);
	res[len] = '\0';
	i = len - 1;
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (num > 9)
	{
		res[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	res[i] = num + '0';
	return (res);
}
