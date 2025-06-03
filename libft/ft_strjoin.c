#include "libft.h"

int	ft_strs_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += (size - 1) * ft_strlen(sep);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	char	*tmp;
	int		i;
	int		total_len;

	if (size == 0)
	{
		joined = (char *)malloc(1);
		if (joined)
			joined[0] = '\0';
		return (joined);
	}
	total_len = ft_strs_len(size, strs, sep);
	joined = (char *)malloc((total_len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	tmp = joined;
	i = 0;
	while (i < size)
	{
		tmp = ft_strcpy(tmp, strs[i]);
		if (i < size - 1)
			tmp = ft_strcpy(tmp, sep);
		i++;
	}
	return (joined);
}
