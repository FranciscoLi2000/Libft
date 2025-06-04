/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 03:57:26 by yufli             #+#    #+#             */
/*   Updated: 2025/06/04 08:55:34 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*curr;

	while (*begin_list && cmp((*begin_list)->content, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp->content);
		free(tmp);
	}
	curr = *begin_list;
	while (curr && curr->next)
	{
		if (cmp(curr->next->content, data_ref) == 0)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			free(tmp->content);
			free(tmp);
		}
		else
			curr = curr->next;
	}
}
