#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	if (little[0] == '\0')
		return (big);
	i = 0;
	while (big[i] && i < len)/* 外层循环:遍历big str直到结束 */
	{
		j = 0;
		while (to_find[j] && i + j < len && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return (NULL);
}
