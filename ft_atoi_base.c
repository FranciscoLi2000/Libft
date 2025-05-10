#include "libft.h"

int	INVALID_BASE = 0;
int	NO_MATCH = 0;

static int	twice_char(char *symbols)
{
	int	i;
	int	j;

	i = 0;
	while (*(symbols + i))
	{
		j = i + 1;
		while (*(symbols + j))
		{
			if (*(symbols + i) == *(symbols + j))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

static int	real_value(char *nbr, char *symbols, int base_value, int position, int sign)
{
	int	i;

	i = 0;
	if (!position)
	{
		while (*nbr != *(symbols + i))
			++i;
		return (i * sign);
	}
	else
	{
		while (*nbr != *(symbols + i))
			++i;
		return (real_value(nbr + 1, symbols, base_value, position - 1, sign)
			+ (i * ft_pow(base_value, position) * sign));
	}
}

static int	symbol_set(char c, char *symbols)
{
	while ((c != *symbols) && *symbols)
		symbols++;
	if (!*symbols)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_value;
	int	position;
	int	sign;

	sign = 1;
	base_value = position = 0;
	while (base[base_value])
	{
		if (base[base_value] == '+' || base[base_value] == '-' || base[base_value] == ' ')
		{
			INVALID_BASE = 1;
			return (0);
		}
		++base_value;
	}
	if (base_value < 2 || twice_char(base))
	{
		INVALID_BASE = 1;
		return (0);
	}
	while (*(str + position))
	{
		while (*str == '+' || *str == '-' || ft_isspace(*str))
		{
			if (*str == '-')
				sign *= -1;
			++str;
		}
		if (!symbol_set(*(str + position), base))
		{
			NO_MATCH = 1;
			return (0);
		}
		++position;
	}
	return (real_value(str, base, base_value, position - 1, sign));
}
