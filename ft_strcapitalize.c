#include "libft.h"

void	strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			new_word = 1;
		if (new_word == 1 && ft_isalpha(str[i]))
		{
			if (ft_islower(str[i]))
				ft_toupper(str[i]);
			new_word = 0;
		}
		else if (new_word == 0 && ft_isupper(str[i]))
			ft_tolower(str[i]);
		i++;
	}
}
