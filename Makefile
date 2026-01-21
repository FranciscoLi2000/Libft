NAME		= libft.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

INCLUDES	= includes

MANDATORY_DIR	= libft_mandatorio
BONUS_DIR	= libft_bonus

MANDATORY_SRCS	= \
		  $(MANDATORY_DIR)/ft_isalpha.c \
		  $(MANDATORY_DIR)/ft_isdigit.c \
		  $(MANDATORY_DIR)/ft_isalnum.c \
		  $(MANDATORY_DIR)/ft_isascii.c \
		  $(MANDATORY_DIR)/ft_isprint.c \
		  $(MANDATORY_DIR)/ft_strlen.c \
		  $(MANDATORY_DIR)/ft_memset.c \
		  $(MANDATORY_DIR)/ft_bzero.c \
		  $(MANDATORY_DIR)/ft_memcpy.c \
		  $(MANDATORY_DIR)/ft_memmove.c \
		  $(MANDATORY_DIR)/ft_strlcpy.c \
		  $(MANDATORY_DIR)/ft_strlcat.c \
		  $(MANDATORY_DIR)/ft_toupper.c \
		  $(MANDATORY_DIR)/ft_tolower.c \
		  $(MANDATORY_DIR)/ft_strchr.c \
		  $(MANDATORY_DIR)/ft_strrchr.c \
		  $(MANDATORY_DIR)/ft_strncmp.c \
		  $(MANDATORY_DIR)/ft_memchr.c \
		  $(MANDATORY_DIR)/ft_memcmp.c \
		  $(MANDATORY_DIR)/ft_strnstr.c \
		  $(MANDATORY_DIR)/ft_atoi.c \
		  $(MANDATORY_DIR)/ft_calloc.c \
		  $(MANDATORY_DIR)/ft_strdup.c \
		  $(MANDATORY_DIR)/ft_substr.c \
		  $(MANDATORY_DIR)/ft_strjoin.c \
		  $(MANDATORY_DIR)/ft_strtrim.c \
		  $(MANDATORY_DIR)/ft_split.c \
		  $(MANDATORY_DIR)/ft_itoa.c \
		  $(MANDATORY_DIR)/ft_putchar_fd.c \
		  $(MANDATORY_DIR)/ft_putstr_fd.c \
		  $(MANDATORY_DIR)/ft_putendl_fd.c \
		  $(MANDATORY_DIR)/ft_putnbr_fd.c

BONUS_SRCS	= \
		  $(BONUS_DIR)/ft_lstnew.c \
		  $(BONUS_DIR)/ft_lstadd_front.c \
		  $(BONUS_DIR)/ft_lstsize.c \
		  $(BONUS_DIR)/ft_lstlast.c \
		  $(BONUS_DIR)/ft_lstadd_back.c \
		  $(BONUS_DIR)/ft_lstdelone.c \
		  $(BONUS_DIR)/ft_lstclear.c \
		  $(BONUS_DIR)/ft_lstiter.c \
		  $(BONUS_DIR)/ft_lstmap.c

MANDATORY_OBJS	= $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(MANDATORY_OBJS)
	$(AR) $(NAME) $(MANDATORY_OBJS)

bonus: $(MANDATORY_OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(MANDATORY_OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
