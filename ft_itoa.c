/* Regla mental: “Cuenta dígitos → malloc → rellena desde atrás.” */

#include "libft.h"

static size_t	num_len(int n)
{
	size_t	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*res;

	nb = n;
	len = num_len(nb);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		res[0] = '0';
	while (nb)
	{
		res[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
/* Hack mental: escribir números al revés. */
