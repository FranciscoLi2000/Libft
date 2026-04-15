#include "libft.h"

void*ft_memset(void *b, int c, size_t len)
{
size_ti;
unsigned char*ptr;

ptr = (unsigned char *)b;
i = 0;
while (i < len)
{
ptr[i] = (unsigned char)c;
i++;
}
return (b);
}
