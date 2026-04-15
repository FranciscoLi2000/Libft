#include "libft.h"

voidft_putnbr_fd(int n, int fd)
{
longnb;

nb = n;
if (nb < 0)
{
ft_putchar_fd('-', fd);
nb = -nb;
}
if (nb >= 10)
ft_putnbr_fd(nb / 10, fd);
ft_putchar_fd((nb % 10) + '0', fd);
}
