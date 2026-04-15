#include "libft_bonus.h"

intft_lstsize(t_list *lst)
{
intsize;

size = 0;
while (lst)
{
size++;
lst = lst->next;
}
return (size);
}
