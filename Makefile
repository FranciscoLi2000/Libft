# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 09:52:32 by yufli             #+#    #+#              #
#    Updated: 2025/06/04 09:53:27 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I includes
AR			= ar rcs
RM			= rm -f

# Colors
GREEN		= \033[0;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
RED			= \033[0;31m
RESET		= \033[0m

SRCS		= libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
			  libft/ft_isdigit.c libft/ft_isprint.c libft/ft_strlen.c \
			  libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c \
			  libft/ft_memmove.c libft/ft_strlcpy.c libft/ft_strlcat.c \
			  libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c \
			  libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c \
			  libft/ft_atoi.c libft/ft_itoa.c libft/ft_strdup.c \
			  libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c \
			  libft/ft_split.c libft/ft_strmapi.c libft/ft_striteri.c \
			  libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
			  libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
			  libft/ft_tolower.c libft/ft_toupper.c libft/ft_putchar.c \
			  libft/ft_putstr.c libft/ft_strcmp.c libft/ft_strcpy.c \
			  libft/ft_strncpy.c libft/ft_strncat.c libft/ft_strcat.c \
			  libft/ft_strspn.c libft/ft_strcspn.c libft/ft_strpbrk.c \
			  libft/ft_strstr.c libft/ft_strrev.c libft/ft_range.c \
			  libft/ft_rrange.c libft/ft_atoi_base.c libft/ft_isspace.c \
			  libft/is_power_of_2.c libft/lcm.c libft/max.c \
			  libft/print_bits.c libft/reverse_bits.c libft/swap_bits.c \
			  libft/ft_is_prime.c

BONUS_SRCS	= lib_bonus/ft_lstnew_bonus.c lib_bonus/ft_lstadd_front_bonus.c \
			  lib_bonus/ft_lstadd_back_bonus.c lib_bonus/ft_lstsize_bonus.c \
			  lib_bonus/ft_lstlast_bonus.c lib_bonus/ft_lstdelone_bonus.c \
			  lib_bonus/ft_lstclear_bonus.c lib_bonus/ft_lstiter_bonus.c \
			  lib_bonus/ft_lstmap_bonus.c lib_bonus/ft_list_foreach.c \
			  lib_bonus/ft_list_remove_if.c lib_bonus/sort_int_tab.c \
			  lib_bonus/sort_list.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)[Compiling]$(RESET) Creating $(NAME)..."
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)[Success]$(RESET) Library built."

bonus: $(OBJS) $(BONUS_OBJS)
	@echo "$(YELLOW)[Bonus]$(RESET) Compiling with bonus files..."
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(GREEN)[Success]$(RESET) Bonus library built."

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(RED)[Clean]$(RESET) Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)[Fclean]$(RESET) Library removed."

re: fclean all

.PHONY: all bonus clean fclean re
