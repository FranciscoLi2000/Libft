#include "libft.h"

/* ft_lstdelone - Delete single node */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	lst->content_size = 0;
	lst->next = NULL;
	free(lst);
}
