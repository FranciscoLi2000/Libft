#include "libft.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*tmp;
	void	*swap;
	int		a;
	int		b;

	tmp = lst;
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			a = *(int *)lst->content;
			b = *(int *)tmp->content;
			if (cmp(a, b) == 0)
			{
				swap = lst->content;
				lst->content = tmp->content;
				tmp->content = swap;
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (lst);
}
