/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:08:56 by yufli             #+#    #+#             */
/*   Updated: 2025/05/21 17:23:43 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:
*/

/* STRPBRK(3) (simplified)

NAME
     strpbrk –- locate multiple characters in string
LIBRARY
     Standard C Library (libc, -lc)
SYNOPSIS
     #include <string.h>
     char *strpbrk(const char *s, const char *charset);

DESCRIPTION
     The strpbrk() function locates in the null-terminated string s the first
     occurrence of any character in the string charset and returns a pointer to this
     character.  If no characters from charset occur anywhere in s strpbrk()
     returns NULL.
RETURN VALUES
     The strpbrk() function return a pointer to the first occurence of any character
     in the string,if no characters occur anywhere in s, strpbrk() returns NULL. */

#include "exam.h"

char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	while (*s1)
	{
		tmp = s2;
		while (*tmp)
		{
			if (*tmp == *s1)
				return ((char *)s1);
			tmp++;
		}
		s1++;
	}
	return (NULL);
}

#include <stdio.h>
int	main(void)
{
	char *s = "pineapple";
	char *charset = "abcde";
	char *res = ft_strpbrk(s, charset);

	printf("%s\n", res);
	return (0);
}
