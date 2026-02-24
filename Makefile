NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

INCLUDES = -Iincludes

SRC_DIR = src
BONUS_DIR = bonus

SRCS = \
       $(SRC_DIR)/ft_strlen.c \
       $(SRC_DIR)/ft_strdup.c \
       $(SRC_DIR)/ft_memcpy.c \
       $(SRC_DIR)/ft_memmove.c \
       $(SRC_DIR)/ft_memset.c \
       $(SRC_DIR)/ft_bzero.c \
       $(SRC_DIR)/ft_atoi.c \
       $(SRC_DIR)/ft_split.c \
       $(SRC_DIR)/ft_substr.c \
       $(SRC_DIR)/ft_strjoin.c \
       $(SRC_DIR)/ft_strtrim.c \
       $(SRC_DIR)/ft_strchr.c \
       $(SRC_DIR)/ft_strrchr.c \
       $(SRC_DIR)/ft_strncmp.c \
       $(SRC_DIR)/ft_strnstr.c \
       $(SRC_DIR)/ft_strlcpy.c \
       $(SRC_DIR)/ft_strlcat.c \
       $(SRC_DIR)/ft_putchar_fd.c \
       $(SRC_DIR)/ft_putstr_fd.c \
       $(SRC_DIR)/ft_putendl_fd.c \
       $(SRC_DIR)/ft_putnbr_fd.c \
       $(SRC_DIR)/ft_itoa.c \
       $(SRC_DIR)/ft_calloc.c \
       \
       $(SRC_DIR)/get_next_line.c \
       $(SRC_DIR)/get_next_line_utils.c \
       \
       $(SRC_DIR)/printf.c \
       $(SRC_DIR)/printf_char.c \
       $(SRC_DIR)/printf_numbers.c \
       $(SRC_DIR)/printf_printers.c

BONUS_SRCS = \
	     $(BONUS_DIR)/ft_lstnew_bonus.c \
	     $(BONUS_DIR)/ft_lstadd_front_bonus.c \
	     $(BONUS_DIR)/ft_lstadd_back_bonus.c \
	     $(BONUS_DIR)/ft_lstclear_bonus.c \
	     $(BONUS_DIR)/ft_lstdelone_bonus.c \
	     $(BONUS_DIR)/ft_lstiter_bonus.c \
	     $(BONUS_DIR)/ft_lstlast_bonus.c \
	     $(BONUS_DIR)/ft_lstmap_bonus.c \
	     $(BONUS_DIR)/ft_lstsize_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

TEST = tester
TEST_SRC = test/tester.c

test: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) -D BUFFER_SIZE=42 $(TEST_SRC) $(NAME) -o $(TEST)
	./$(TEST)

.PHONY: all clean fclean re bonus test
