/* Regla mental: borrar contenido → borrar nodo → NO tocar next */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* Importantísimo: no liberar lst->next. */

