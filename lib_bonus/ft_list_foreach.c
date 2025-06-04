/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 03:53:30 by yufli             #+#    #+#             */
/*   Updated: 2025/06/04 03:56:36 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list || !f)
		return ;
	while (begin_list != NULL)
	{
		if (begin_list->content != NULL)
			(*f)(begin_list->content);
		begin_list = begin_list->next;
	}
}
