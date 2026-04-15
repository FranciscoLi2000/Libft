#include "libft.h"

static size_tft_digits(long n)
{
size_tcount;

count = 1;
while (n >= 10)
{
n /= 10;
count++;
}
return (count);
}

char*ft_itoa(int n)
{
char*str;
longnb;
size_tlen;

nb = n;
len = ft_digits((nb < 0) * (-nb) + (nb >= 0) * nb) + (nb < 0);
str = (char *)malloc(len + 1);
if (!str)
return (NULL);
str[len] = '\0';
if (nb < 0)
nb = -nb;
while (len-- > (size_t)(n < 0))
{
str[len] = (nb % 10) + '0';
nb /= 10;
}
if (n < 0)
str[0] = '-';
return (str);
}
