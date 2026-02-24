/* ft_itoa.c - Integer to string */
/* Description: Generates a string representation of the integer n */

#include "libft.h"

static size_t	ft_count_digits(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	length;
	size_t	i;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = ft_count_digits(n);
	str = malloc(length + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	i = length - 1;
	while (i > 0 && n > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	str[0] = '0' + n;
	str[length] = '\0';
	return (str);
}
