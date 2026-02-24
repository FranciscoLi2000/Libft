/* ft_strjoin.c - Join strings */
/* Description: Allocates and returns a new string, which is the result of the concatenation of s1 and s2 */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	length1;
	size_t	length2;
	char	*join;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	length1 = ft_strlen(s1);
	length2 = ft_strlen(s2);
	join = malloc(length1 + length2 + 1);
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, length1 + 1);
	ft_strlcat(join, s2, length1 + length2 + 1);
	return (join);
}
