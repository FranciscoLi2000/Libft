#include "libft.h"

int	max(int *tab, unsigned int len)
{
	int	max_val;
	int	i;
	unsigned int	count;

	count = i = max_val = 0;
	if (len > 0)
	{
		while (count < len)
		{
			if (tab[i] > max_val)
				max_val = tab[i];
			i++;
			count++;
		}
		return (max_val);
	}
	return (0);
}
