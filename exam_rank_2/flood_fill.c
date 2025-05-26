/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:02:14 by yufli             #+#    #+#             */
/*   Updated: 2025/05/23 23:02:34 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exam.h"

void	fill_recursive(char **tab, t_point size, int row, int col, char target_char)
{
	if (col < 0 || row < 0 || col >= size.x || row >= size.y)
		return ;
	if (tab[row][col] == target_char)
		return ;
	tab[row][col] = 'F';
	fill_recursive(tab, size, row - 1, col, target_char);
	fill_recursive(tab, size, row + 1, col, target_char);
	fill_recursive(tab, size, row, col - 1, target_char);
	fill_recursive(tab, size, row, col + 1, target_char);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target_char;

	if (begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y)
		return ;
	target_char = tab[begin.y][begin.x];
	if (target_char == 'F')
		return ;
	fill_recursive(tab, size, begin.y, begin.x, target_char);
}
