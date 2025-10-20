#include "libft.h"

/* 辅助函数：判断字符c是否在字符串set中 */
static int	char_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*result;
	size_t	i;

	if (!s1 || !set)/* 边界检查 */
		return (malloc(1));
	len = ft_strlen(s1);/* 获取字符串长度 */
	start = 0;/* 第一步：从左边找到第一个\"不在set中\"的字符 */
	while (start < len && char_in_set(s1[start], set))/* 这个循环会一直往右走，只要当前字符在set中 */
		start++;
	if (start >= len)/* 特殊情况：如果整个字符串都是垃圾字符 */
	{
		result = malloc(1);/* 那么start已经达到len或更远，我们应该返回空字符串 */
		if (result)/* 返回只包含\0的空字符串 */
			result[0] = '\0';
		return (result);
	}
	end = len - 1;/* 第二步：从右边找到最后一个\"不在set中\"的字符 */
	while (end > start && char_in_set(s1[end], set))/* 注意：end初始化为len-1（最后一个有效索引） */
		end--;/* 循环条件是end > start保证我们不会越过start */
	result = malloc(end - start + 2);/* 第三步：分配内存，需要加1个字符 + 1个字节放\0 */
	if (!result)
		return (NULL);
	i = 0;
	while (i < trimmed_len)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[trimmed_len] = '\0';
	return (result);
}
