#include "libft.h"

static unsigned int	num_len(int n)
{
	int	len;

	if (n <= 0)
	{
		len = 1;
		while (n)
		{
			n = n / 10;
			len++;
		}
	}
	else
	{
		len = 0;
		while (n)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	len = num_len(n);
	num = n;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		len--;
		str[len] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}
