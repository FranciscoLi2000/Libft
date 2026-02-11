# libft Makefile
# Author: Yufeng Li
# Description: Build system for libft, ft_printf, and get_next_line

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Isrc/printf -Isrc/get_next_line
AR = ar
ARFLAGS = rcs

# Project names and targets
NAME = libft.a
LIBFT_SRCDIR = src/libft
PRINTF_SRCDIR = src/printf
GNL_SRCDIR = src/get_next_line

# Source files
LIBFT_SRC = $(wildcard *.c)
LIBFT_SRC := $(filter-out src/printf/%.c src/get_next_line/%.c, $(LIBFT_SRC))
LIBFT_SRC := $(filter-out get_next_line.c ft_putnbr_fd.c ft_putunbr_fd.c ft_puthex_fd.c, $(LIBFT_SRC))

PRINTF_SRC = $(wildcard $(PRINTF_SRCDIR)/*.c)
GNL_SRC = $(wildcard $(GNL_SRCDIR)/*.c)

# Object files
LIBFT_OBJ = $(LIBFT_SRC:%.c=%.o)
PRINTF_OBJ = $(PRINTF_SRC:%.c=%.o)
GNL_OBJ = $(GNL_SRC:%.c=%.o)

# Bonus files (will be created later)
BONUS_SRC = $(wildcard bonus/*.c)
BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

# Rules
all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	@echo "Creating libft library..."
	$(AR) $(ARFLAGS) $(NAME) $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	@echo "✓ Library created successfully"

# Compile object files
%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Bonus rule (optional)
bonus: $(BONUS_OBJ)
	@echo "Adding bonus files to library..."
	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJ)
	@echo "✓ Bonus features added"

# Clean rules
clean:
	@echo "Cleaning object files..."
	rm -f $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ) $(BONUS_OBJ)
	@echo "✓ Object files removed"

fclean: clean
	@echo "Cleaning library file..."
	rm -f $(NAME)
	@echo "✓ Library file removed"

# Rebuild everything
re: fclean all

# Test rule
test: all
	@echo "Running tests..."
	@if [ -f test_libft ]; then \
		./test_libft; \
	else \
		echo "No test program found. Create test_libft"; \
	fi

# Install rule (optional)
install: all
	@echo "Installing library to /usr/local/lib..."
	cp $(NAME) /usr/local/lib/
	cp libft.h /usr/local/include/
	cp src/printf/ft_printf.h /usr/local/include/
	cp src/get_next_line/get_next_line.h /usr/local/include/
	@echo "✓ Library installed"

# Print variables for debugging
debug:
	@echo "LIBFT_SRC: $(LIBFT_SRC)"
	@echo "PRINTF_SRC: $(PRINTF_SRC)"
	@echo "GNL_SRC: $(GNL_SRC)"
	@echo "LIBFT_OBJ: $(LIBFT_OBJ)"
	@echo "PRINTF_OBJ: $(PRINTF_OBJ)"
	@echo "GNL_OBJ: $(GNL_OBJ)"

.PHONY: all clean fclean re test install bonus debug
