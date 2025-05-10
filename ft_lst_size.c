#include "libft.h"

int	ft_lst_size(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		++count;
		lst = lst->next;
	}
	return (count);
}
