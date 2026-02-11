/* _bonus.c - Bonus list functions */
/* Author: your_login */
/* Description: Implementation of bonus list manipulation functions */

/*
 * ft_lstnew - Create new list node
 * ft_lstadd_front - Add node to front of list
 * ft_lstsize - Count list size
 * ft_lstlast - Get last node
 * ft_lstadd_back - Add node to back of list
 * ft_lstdelone - Delete single node
 * ft_lstclear - Clear entire list
 * ft_lstiter - Iterate list with function
 * ft_lstmap - Map list with function
 */

#include "libft.h"

/* ft_lstnew - Create new list node */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->content_size = 0;
	node->next = NULL;
	return (node);
}

/* ft_lstadd_front - Add node to front of list */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return;
	new->next = *lst;
	*lst = new;
}

/* ft_lstsize - Count list size */
int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/* ft_lstlast - Get last node */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/* ft_lstadd_back - Add node to back of list */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/* ft_lstdelone - Delete single node */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return;
	del(lst->content);
	lst->content_size = 0;
	lst->next = NULL;
	 free(lst);
}

/* ft_lstclear - Clear entire list */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		lst = NULL;
		current->content_size = 0;
		current->next = NULL;
	 free(current);
		current = next;
	}
	*lst = NULL;
}

/* ft_lstiter - Iterate list with function */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (lst == NULL || f == NULL)
		return;
	current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}

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