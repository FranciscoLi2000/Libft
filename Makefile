# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 09:52:32 by yufli             #+#    #+#              #
#    Updated: 2025/06/06 19:33:37 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== CONFIG ==========
NAME		= libft.a

# Directories
LIB_DIR		= libft
OBJDIR		= obj
INCDIR		= includes

# Source files split by module
LIBFT_FILES	= \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncat.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SRC_FILES	= $(addprefix $(LIB_DIR)/, $(LIBFT_FILES))

OBJ_FILES	= $(addprefix $(OBJDIR)/, $(notdir $(SRC_FILES:.c=.o)))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INCDIR)
AR			= ar rcs
RM			= rm -rf
MKDIR		= mkdir -p

# ========== COLORS ==========
GREEN	= \033[0;32m
BLUE	= \033[0;34m
RED		= \033[0;31m
RESET	= \033[0m

# ========== RULES ==========

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(BLUE)🔧 Archiving $(NAME)...$(RESET)"
	$(AR) $(NAME) $(OBJ_FILES)
	@echo "$(GREEN)Build complete!$(RESET)"

# Compile .c → obj/ .o
$(OBJDIR)/%.o: $(LIB_DIR)/%.c | $(OBJDIR)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(GNL_DIR)/%.c | $(OBJDIR)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj directory
$(OBJDIR):
	@$(MKDIR) $(OBJDIR)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	$(RM) $(OBJDIR) $(OBJ_FILES)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re