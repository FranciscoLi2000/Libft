# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 11:28:06 by yufli             #+#    #+#              #
#    Updated: 2025/05/19 12:05:27 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de la librería
NAME = libft.a

# Directorios
SRCDIR = libft
BONUSDIR = lib_bonus
INCDIR = includes
OBJDIR = obj

# Archivos fuente
SRCS = $(addprefix $(SRCDIR)/, \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
)

# Archivos bonus
BONUS_SRCS = $(addprefix $(BONUSDIR)/, \
	ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c \
)

# Archivos objeto
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUSDIR)/%.c=$(OBJDIR)/%.o)

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INCDIR)

# Comandos
AR = ar rcs
RM = rm -f

# Colores para output
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m # No Color

# Regla principal
all: $(NAME)

# Crear la librería
$(NAME): $(OBJS)
	@echo "$(YELLOW)Creando librería $(NAME)...$(NC)"
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) creada exitosamente!$(NC)"

# Compilar archivos objeto del directorio principal
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compilando $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilar archivos objeto del directorio bonus
$(OBJDIR)/%.o: $(BONUSDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compilando $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Regla bonus
bonus: $(OBJS) $(BONUS_OBJS)
	@echo "$(YELLOW)Creando librería con bonus $(NAME)...$(NC)"
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(GREEN)✓ $(NAME) con bonus creada exitosamente!$(NC)"

# Limpiar archivos objeto
clean:
	@echo "$(RED)Eliminando archivos objeto...$(NC)"
	@$(RM) -r $(OBJDIR)
	@echo "$(GREEN)✓ Archivos objeto eliminados!$(NC)"

# Limpiar todo
fclean: clean
	@echo "$(RED)Eliminando $(NAME)...$(NC)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ $(NAME) eliminada!$(NC)"

# Recompilar todo
re: fclean all

# Reglas especiales
.PHONY: all clean fclean re bonus

# Crear un target para mostrar información
info:
	@echo "$(YELLOW)=== Información del proyecto ===$(NC)"
	@echo "Nombre de la librería: $(NAME)"
	@echo "Archivos fuente: $(words $(SRCS)) archivos"
	@echo "Archivos bonus: $(words $(BONUS_SRCS)) archivos"
	@echo "Compilador: $(CC)"
	@echo "Flags: $(CFLAGS)"
	@echo "$(YELLOW)===============================$(NC)"

# Target para verificar norminette (opcional)
norm:
	@echo "$(YELLOW)Verificando norminette...$(NC)"
	@norminette $(SRCS) $(BONUS_SRCS) $(INCDIR)/libft.h || true

# Target para testing (opcional)
test: $(NAME)
	@echo "$(YELLOW)Compilando programa de prueba...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -L. -lft test.c -o test_libft 2>/dev/null || echo "$(RED)No se encontró test.c$(NC)"
