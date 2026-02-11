/* test_libft.c - Test program for libft, ft_printf, and get_next_line */
/* Author: your_login */
/* Description: Test program to verify the functionality of libft library */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

int main(void)
{
	/* Test libft functions */
	ft_putstr_fd("Testing libft functions:\n", 1);
	
	/* Test ft_strlen */
	size_t len = ft_strlen("Hello, world!");
	ft_printf("ft_strlen: %zu\n", len);
	
	/* Test ft_atoi */
	int num = ft_atoi("12345");
	ft_printf("ft_atoi: %d\n", num);
	
	/* Test ft_substr */
	char *sub = ft_substr("Hello, world!", 7, 5);
	ft_printf("ft_substr: %s\n", sub);
	
	/* Test ft_split */
	char *str = "Hello,world,from,libft";
	char **words = ft_split(str, ',');
	for (int i = 0; words[i] != NULL; i++)
	{
		ft_printf("ft_split[%d]: %s\n", i, words[i]);
	}
	
	/* Test ft_printf */
	ft_putstr_fd("\nTesting ft_printf:\n", 1);
	ft_printf("ft_printf: %d, %u, %x, %X, %c, %s, %p\n", 42, 255, 255, 255, 'A', "test", (void*)0x1234);
	
	/* Test get_next_line */
	ft_putstr_fd("\nTesting get_next_line:\n", 1);
	int fd = open("test.txt", O_RDONLY);
	if (fd >= 0)
	{
		char *line;
		while ((line = get_next_line(fd)) != NULL)
		{
			ft_printf("Line: %s\n", line);
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			ft_putendl_fd(line, 1);
			ft_strlen(line);
			ft_putchar_fd('\n', 1);
		}
		close(fd);
	}
	
	/* Test bonus functions */
	ft_putstr_fd("\nTesting bonus functions:\n", 1);
	t_list *lst = ft_lstnew("First");
	ft_lstadd_back(&lst, ft_lstnew("Second"));
	ft_lstadd_back(&lst, ft_lstnew("Third"));
	
	int size = ft_lstsize(lst);
	ft_printf("List size: %d\n", size);
	
	ft_putstr_fd("List contents: ", 1);
	t_list *current = lst;
	while (current != NULL)
	{
		ft_putstr_fd((char*)current->content, 1);
		if (current->next != NULL)
			ft_putstr_fd(", ", 1);
		current = current->next;
	}
	ft_putchar_fd('\n', 1);
	
	return (0);
}