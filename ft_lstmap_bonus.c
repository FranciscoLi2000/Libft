/* Esta es la jefa final, pero con pasos claros es easy.
 *
 * Regla mental en 5 pasos:
 * 1.	recorrer lista original
 * 2.	aplicar f al contenido
 * 3.	crear nuevo nodo
 * 4.	añadirlo a la nueva lista
 * 5.	si falla → limpiar todo y NULL
 */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/* Clave absoluta: si algo falla → no leaks, no mercy, limpiar todo. */

