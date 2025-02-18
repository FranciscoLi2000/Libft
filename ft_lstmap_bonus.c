#include "libft.h"
/*
static t_list	*create_new_node(void *content, void (*del)(void *))
{
	t_list	*new_node;

	new_node = ft_lstnew(content);
	if (!new_node)
	{
		del(content);
		return (NULL);
	}
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_node = create_new_node(new_content, del);
		if (!new_content || !new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	/* check if lst or f or del is NULL */
	if (!lst || !f || !del)
		return (NULL);
	/* loop over lst */
	while (lst)
	{
		/* create a new element */
		new_node = ft_lstnew(f(lst->content));
		/* if new elem is null, clear the new list */
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		/* add the new element to the back of the list */
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	/* finally, return the new list */
	return (new_list);
}