#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "libft_bonus.h"

static void print_item(void *content)
{
printf("%s ", (char *)content);
}

static void free_item(void *content)
{
free(content);
}

static void to_upper_str(char *s)
{
unsigned int i;

i = 0;
while (s[i])
{
s[i] = (char)ft_toupper(s[i]);
i++;
}
}

static void print_split(char **arr)
{
int i;

i = 0;
while (arr && arr[i])
{
printf("[%s] ", arr[i]);
free(arr[i]);
i++;
}
free(arr);
printf("\n");
}

int main(void)
{
char	**parts;
t_list *lst;

printf("isalpha(A)=%d strlen(42)=%zu\n", ft_isalpha('A'), ft_strlen("42"));
printf("strnstr=%s atoi=%d\n", ft_strnstr("hello42", "42", 7), ft_atoi(" -123"));
parts = ft_split("libft-is-awesome", '-');
print_split(parts);
lst = ft_lstnew(ft_strdup("libft"));
ft_lstadd_back(&lst, ft_lstnew(ft_strdup("bonus")));
ft_lstiter(lst, print_item);
printf("\nsize=%d last=%s\n", ft_lstsize(lst), (char *)ft_lstlast(lst)->content);
to_upper_str((char *)lst->content);
printf("first=%s\n", (char *)lst->content);
ft_lstclear(&lst, free_item);
return (0);
}
