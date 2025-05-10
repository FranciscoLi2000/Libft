#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char		ch;
	const char	*last;

	ch = (char)c;
	last = NULL;
	do
	{
		if (*str == ch)
			last = str;
	}	while (*str++);
	return ((char *)last);
}
