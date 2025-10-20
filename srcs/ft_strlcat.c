#include "libft.h"

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	j;

	dst_len = 0;/* 计算dst的当前长度 */
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	src_len = ft_strlen(src);/* 计算src的长度 */
	if (dst_len == size)/* 如果size太小,dst_len会等于size,这意味着没有空间追加 */
		return (size + src_len);/* 在这种情况下,返回size + src_len */
	i = dst_len;/* 从dst的末尾开始追加src的字符 *//* i指向dst中'\0'的位置 */
	j = 0;/* j指向src的开头 */
	while (src[j] && i < size - 1)/* 复制字符,确保不超过size - 1(为终止符留位置) */
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';/* 添加终止符 */
	return (dst_len + src_len);/* 返回尝试创建的字符串长度 */
}
