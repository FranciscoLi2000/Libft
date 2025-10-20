#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;
	size_t	actual_len;
	size_t	i;

	if (!s)/* 边界检查：如果输入字符串是NULL，返回空字符串 */
		return (malloc(1));
	s_len = ft_strlen(s);/* 获取原字符串的实际长度 */
	if (start >= s_len)/* 如果start位置已经超过或等于字符串长度，无法截取任何字符 */
	{
		result = malloc(1);/* 应该返回只包含\0的空字符串 */
		if (result)
			result[0] = '\0';
		return (result);
	}
	actual_len = s_len - start;/* 计算实际能复制的字符数 */
	if (actual_len > len)/* 从start位置开始能复制的最大字符数是：s_len - start */
		actual_len = len;/* 但我们只能复制len个字符（如果有那么多的话），所以取两者的最小值 */
	result = malloc(actual_len + 1);/* 分配内存：actual_len个字符 + 1个字节放\0 */
	if (!result)
		return (NULL);/* malloc失败返回NULL */
	i = 0;/* 从原字符串的start位置复制actual_len个字符到result */
	while (i < actual_len)/* 这里使用了strncpy或手动复制都可以，下面用手动复制更清晰 */
	{
		result[i] = s[start + i];
		i++;
	}
	result[actual_len] = '\0';/* 添加字符串终止符 */
	return (result);
}
