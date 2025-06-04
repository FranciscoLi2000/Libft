/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 08:59:42 by yufli             #+#    #+#             */
/*   Updated: 2025/06/04 13:26:01 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_content(t_list *a, t_list *b)
{
	int	tmp;

	tmp = *((int *)a->content);
	*((int *)a->content) = *((int *)b->content);
	*((int *)b->content) = tmp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*curr;
	int		swap;

	if (!lst)
		return (NULL);
	swap = 1;
	while (swap)
	{
		swap = 0;
		curr = lst;
		while (curr->next)
		{
			if (!cmp(*((int *)curr->content),
					*((int *)curr->next->content)))
			{
				swap_content(curr, curr->next);
				swap = 1;
			}
			curr = curr->next;
		}
	}
	return (lst);
}
