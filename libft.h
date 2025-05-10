#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <errno.h>

typedef struct s_list
{
	void		*content;
	struct s_list	*next;
}	t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_pow(int base, int pow);
size_t		ft_strlen(const char *str);
void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dst, char *src, unsigned int size);
int				ft_islower(int c);
int				ft_toupper(int c);
int				ft_isupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, size_t len);
int				ft_atoi(char *str);
int				ft_atoi_base(char *str, char *base);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_strcpy(char *s1, char *s2);
void			ft_swap(int *a, int *b);
int				ft_strcmp(char *s1, char *s2);
size_t			ft_strcspn(const char *s, const char *reject);
size_t			ft_strspn(const char *s, const char *accept);
char			*ft_strpbrk(const char *s1, const char *s2);
char			*ft_strrev(char *str);
int				is_power_of_2(unsigned int n);
int				max(int *tab, unsigned int len);
void			print_bits(unsigned char octet);
unsigned char		reverse_bits(unsigned char octet);
unsigned char		swap_bits(unsigned char octet);
char			**ft_split(char const *s, char c);
int				*ft_range(int start, int end);
int				*ft_rrange(int start, int end);
unsigned int		lcm(unsigned int a, unsigned int b);
int				ft_is_prime(int nb);
int				ft_find_next_prime(int nb);
void			strcapitalize(char *str);
char			*ft_itoa(int nbr);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr(int nbr);
void			ft_putnbr_base(int nbr, char *base);
void			ft_putnbr_fd(int nbr, int fd);
void			sort_int_tab(int *tab, unsigned int size);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **list, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void			ft_list_foreach(t_list *begin_list, void (*f)(void *));
void			ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
t_list			*sort_list(t_list *lst, int (*cmp)(int, int));

#endif
