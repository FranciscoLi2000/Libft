/* ft_striteri.c - Iterate string with function */
/* Description: Applies the function f to each character of the string s, passing its index as first argument */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	length;
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	length = ft_strlen(s);
	i = 0;
	while (i < length)
	{
		f(i, &s[i]);
		i++;
	}
}
