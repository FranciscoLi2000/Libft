#include "libft.h"
/* 先用辗转相除算出最大公约数 */
/* 最小公倍数 */
unsigned int	lcm(unsigned int a, unsigned int b)	/* for example a = 12 , b = 18 */
{
	unsigned int	gcd;
	unsigned int	temp;
	unsigned int	remainder;

	if (a == 0 || b == 0)
		return (0);
	gcd = a;
	temp = b;
	while (temp != 0)
	{
		remainder = gcd % temp;
		gcd = temp;
		temp = remainder;
	}
	return ((a / gcd) * b);
}
