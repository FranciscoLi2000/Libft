#include "libft.h"

int	*ft_range(int start, int end)
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
		if (start < end)
			tab[i] = start++;
		else
			tab[i] = start--;
		i++;
	}
	return (tab);
}
