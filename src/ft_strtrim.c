#include "libft.h"

static intft_in_set(char c, char const *set)
{
while (*set)
{
if (*set == c)
return (1);
set++;
}
return (0);
}

char*ft_strtrim(char const *s1, char const *set)
{
size_tstart;
size_tend;

if (!s1 || !set)
return (NULL);
start = 0;
end = ft_strlen(s1);
while (s1[start] && ft_in_set(s1[start], set))
start++;
while (end > start && ft_in_set(s1[end - 1], set))
end--;
return (ft_substr(s1, start, end - start));
}
