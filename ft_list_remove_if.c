#include "libft.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;

	if (!begin_list || !*begin_list)
		return ;
	if (cmp(data_ref, (*begin_list)->content) == 0)
	{
		current = *begin_list;
		*begin_list = (*begin_list)->next;
		free(current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
		ft_list_remove_if(&((*begin_list)->next), data_ref, cmp);
}
