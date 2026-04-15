#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include "libft.h"

typedef struct s_list
{
void*content;
struct s_list*next;
}t_list;

t_list*ft_lstnew(void *content);
voidft_lstadd_front(t_list **lst, t_list *new);
intft_lstsize(t_list *lst);
t_list*ft_lstlast(t_list *lst);
voidft_lstadd_back(t_list **lst, t_list *new);
voidft_lstdelone(t_list *lst, void (*del)(void *));
voidft_lstclear(t_list **lst, void (*del)(void *));
voidft_lstiter(t_list *lst, void (*f)(void *));
t_list*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
