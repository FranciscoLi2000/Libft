/* ft_itoa.c - Integer to string */
/* Author: your_login */
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

/* ft_strmapi.c - Map string with function */
/* Author: your_login */
/* Description: Applies the function f to each character of the string s to create a new string */

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	length;
	size_t	i;
	char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	length = ft_strlen(s);
	result = malloc(length + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[length] = '\0';
	return (result);
}