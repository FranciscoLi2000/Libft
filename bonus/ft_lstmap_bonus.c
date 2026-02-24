#include "libft.h"

/* ft_lstmap - Map list with function */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*current;
	t_list	*new;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	result = NULL;
	current = lst;
	while (current != NULL)
	{
		new = ft_lstnew(f(current->content));
		if (new == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new);
		current = current->next;
	}
	return (result);
}
