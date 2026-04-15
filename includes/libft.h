#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

intft_isalpha(int c);
intft_isdigit(int c);
intft_isalnum(int c);
intft_isascii(int c);
intft_isprint(int c);
size_tft_strlen(const char *s);
void*ft_memset(void *b, int c, size_t len);
voidft_bzero(void *s, size_t n);
void*ft_memcpy(void *dst, const void *src, size_t n);
void*ft_memmove(void *dst, const void *src, size_t len);
size_tft_strlcpy(char *dst, const char *src, size_t dstsize);
size_tft_strlcat(char *dst, const char *src, size_t dstsize);
intft_toupper(int c);
intft_tolower(int c);
char*ft_strchr(const char *s, int c);
char*ft_strrchr(const char *s, int c);
intft_strncmp(const char *s1, const char *s2, size_t n);
void*ft_memchr(const void *s, int c, size_t n);
intft_memcmp(const void *s1, const void *s2, size_t n);
char*ft_strnstr(const char *haystack, const char *needle, size_t len);
intft_atoi(const char *str);
void*ft_calloc(size_t count, size_t size);
char*ft_strdup(const char *s1);
char*ft_substr(char const *s, unsigned int start, size_t len);
char*ft_strjoin(char const *s1, char const *s2);
char*ft_strtrim(char const *s1, char const *set);
char**ft_split(char const *s, char c);
char*ft_itoa(int n);
char*ft_strmapi(char const *s, char (*f)(unsigned int, char));
voidft_striteri(char *s, void (*f)(unsigned int, char*));
voidft_putchar_fd(char c, int fd);
voidft_putstr_fd(char *s, int fd);
voidft_putendl_fd(char *s, int fd);
voidft_putnbr_fd(int n, int fd);

#endif
