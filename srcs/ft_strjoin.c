#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);/* 分配内存 */
	if (!result)
		return (NULL);
	i = 0;/* 复制第一个字符串 */
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;/* 复制第二个字符串 */
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';/* 添加结束符 */
	return (result);
}
