/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:00:19 by yufli             #+#    #+#             */
/*   Updated: 2025/05/22 22:40:21 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAM_H
# define EXAM_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
char	*ft_strcpy(char *s1, char *s2);
void	ft_swap(int *a, int *b);
int		ft_islower(int c);
int		ft_isupper(int c);
void	ulstr(char *str);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strcspn(const char *s, const char *reject);
size_t	ft_strspn(const char *s, const char *accept);
char	*ft_strpbrk(const char *s1, const char *s2);
char	*ft_strrev(char *str);
int		is_power_of_2(unsigned int n);
int		max(int* tab, unsigned int len);
void	print_bits(unsigned char octet);
unsigned char	reverse_bits(unsigned char octet);
unsigned char	swap_bits(unsigned char octet);
int	ft_atoi_base(const char *str, int str_base);
int     *ft_range(int start, int end);
int     *ft_rrange(int start, int end);
unsigned int	lcm(unsigned int a, unsigned int b);

#endif
