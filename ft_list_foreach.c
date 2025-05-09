#include "libft.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list || !f)
		return ;
	while (begin_list)
	{
		f(begin_list->content);
		begin_list = begin_list->next;
	}
}
