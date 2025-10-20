#include "libft.h"

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = (unsigned int)ft_strlen(src);/* 首先计算源字符串的长度,这是必须返回的值 */
	if (size == 0)/* 如果size是0,不能写入任何东西,直接返回长度 */
		return (src_len);
	i = 0;/* 复制字符,但最多只能复制size - 1个(为终止符留空间) */
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';/* 总是添加终止符,因为size至少是1(上面已经检查过size == 0) */
	return (src_len);/* 返回源字符串的长度,不是实际复制的字符数 */
}
