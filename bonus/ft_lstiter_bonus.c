#include "libft_bonus.h"

voidft_lstiter(t_list *lst, void (*f)(void *))
{
if (!lst || !f)
return ;
while (lst)
{
f(lst->content);
lst = lst->next;
}
}
