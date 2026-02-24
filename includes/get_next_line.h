#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

/* utils */
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, const char *s2);
char	*ft_gnl_getline(const char *stash);
char	*ft_gnl_newstash(char *stash);

#endif
