# Libft -- to make a 42 library in C 

This repository contains the three first projects of 42 Barcelona Common-Core, the functions of Libft, get_next_line and ft_printf.

# Libft

After the learning of C language during the piscine of 42, we can rewrite some important functions of libc and some other funtions to be used in the future. In this README I gonna tell how can use the functions of this libftprintf library api.

## Mandatory Part

### Part 1 - Functions of libc

`int		 ft_isalpha(int c);`
Use it to check if the character is a letter.
`int		 ft_isdigit(int c);`
Use it to check if the character is a number.
`int		 ft_isalnum(int c);`
Use it to check if the character is a letter or a number.
`int		 ft_isascii(int c);`
Use it to check if the character is in the ASII table (from 0 to 127 in decimal).
`int		 ft_isprint(int c);`
Use it to check if the character is printable (from 32 to 126 in decimal).
`size_t	 ft_strlen(const char *s);`
Count the size of a string.
`void	*ft_memset(void *s, int c, size_t n);`

`void	 ft_bzero(void *s, size_t n);`

`void	*ft_memcpy(void *dest, const void *src, size_t n);`

`void	*ft_memmove(void *dest, const void *src, size_t n);`

`size_t	 ft_strlcpy(char *dest, const char *src, size_t destsize);`

`size_t	 ft_strlcat(char *dest, const char *src, size_t destsize);`

`int		 ft_toupper(int c);`

`int		 ft_tolower(int c);`

`char	*ft_strchr(const char *s, int c);`

`char	*ft_strrchr(const char *s, int c);`

`int		 ft_strncmp(const char *s1, const char *s2, size_t n);`

`void	*ft_memchr(const void *s, int c, size_t n);`

`int		 ft_memcmp(const void *s1, const void *s2, size_t n);`

`char	*ft_strnstr(const char *haystack, const char *needle, size_t len);`

`int		 ft_atoi(const char *str);`

`void	*ft_calloc(size_t count, size_t size);`

`char	*ft_strdup(const char *s);`

### Part 2 - Additional Functions

`char	*ft_substr(const char *s, unsigned int start, size_t len);`

`char	*ft_strjoin(const char *s1, const char *s2);`

`char	*ft_strtrim(const char *s1, const char *set);`

`char	**ft_split(const char *s, char c);`

`char	*ft_itoa(int n);`

`char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));`

`void	 ft_striteri(char *s, void (*f)(unsigned int, char*));`

`void	 ft_putchar_fd(char c, int fd);`

`void	 ft_putstr_fd(const char *s, int fd);`

`void	 ft_putendl_fd(const char *s, int fd);`

`void	 ft_putnbr_fd(int n, int fd);`

## Bonus Part

Linked list Data Structure:
`
typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}	t_list;
`

`t_list	*ft_lstnew(void *content);`

`void	 ft_lstadd_front(t_list **lst, t_list *new);`

`int		 ft_lstsize(t_list *lst);`

`t_list	*ft_lstlast(t_list *lst);`

`void	 ft_lstadd_back(t_list **lst, t_list *new);`

`void	 ft_lstdelone(t_list *lst, void (*del)(void *));`

`void	 ft_lstclear(t_list **lst, void (*del)(void *));`

`void	 ft_lstiter(t_list *lst, void (*f)(void *));`

`t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`

# Get next line

`char	*get_next_line(int fd);`

`size_t	ft_gnl_strlen(const char *s);`

`char	*ft_gnl_strchr(const char *s, int c);`

`char	*ft_gnl_strjoin(char *s1, const char *s2);`

`char	*ft_gnl_getline(const char *stash);`

`char	*ft_gnl_newstash(char *stash);`

# Printf

`int		ft_printf(const char *format, ...);`

`int		ft_print_char(char c);`

`int		ft_print_str(const char *s);`

`int		ft_print_ptr(void *ptr);`

`int		ft_print_int(int n);`

`int		ft_print_uint(unsigned int n);`

`int		ft_print_hex(unsigned int n, int uppercase);`

`int		ft_print_percent(void);`

