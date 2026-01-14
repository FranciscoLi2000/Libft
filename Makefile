NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
              ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	             ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		            ft_strchr.c ft_strrchr.c ft_strncmp.c \
			           ft_memchr.c ft_memcmp.c ft_strnstr.c \
				          ft_atoi.c ft_calloc.c ft_strdup.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# Esto sí se usa en la vida real
#
# Este tipo de lib:
# •	la enlazas en proyectos grandes
# •	la llevas a embedded / sistemas
# •	te ahorra libc incompleta
# •	demuestra que dominas C base de verdad
#
# No es un ejercicio, es fundamento.

