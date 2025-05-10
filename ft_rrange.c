#include "libft.h"

int	*ft_rrange(int start, int end)
{
	int	*tab;
	int	len;
	int	i;

	if (start < end)
		len = end - start + 1;
	else
		len = start - end + 1;
	tab = (int *)malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		if (end < start)
			tab[i] = end++;
		else
			tab[i] = end--;
		i++;
	}
	return (tab);
}
