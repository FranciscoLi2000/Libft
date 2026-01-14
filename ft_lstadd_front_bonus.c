/* Regla mental: new apunta al antiguo primero → ahora new es el primero */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
/* El ** es clave: modificas el inicio real de la lista. */

