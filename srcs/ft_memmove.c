#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)/* 如果目标地址在源地址后面，从后往前复制 */
	{
		i = count;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;/* 否则从前往后复制 */
		while (i < count)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
