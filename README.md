# Libft

## Overview

**Libft** is a custom C standard library developed as the first core project at 42 School.

The goal of this project is to reimplement essential functions from the C standard library and to understand low-level programming concepts such as:

- Memory management
- Pointers
- Strings manipulation
- Linked lists
- Modular programming
- Static libraries

All functions are written following strict coding standards and compiled into a static library (`libft.a`).

---

## Project Structure

includes/   → header files
src/        → mandatory functions
bonus/      → linked list bonus functions
test/       → optional test programs
Makefile    → compilation rules

---

## Compilation

Build the library:

```bash
	make

Build including bonus functions:

	make bonus

Clean object files:

	make clean

Remove everything:

	make fclean

Rebuild:

	make re
```

---

## How to Use

Include the header:

	#include "libft.h"

Compile with:

	cc main.c libft.a -Iincludes

---

**Character Functions**

---

	int ft_isalpha(int c);

Checks if a character is alphabetic (A-Z or a-z).

---

	int ft_isdigit(int c);

Checks if a character is numeric.

---

	int ft_isalnum(int c);

Checks if a character is alphabetic or numeric.

---

	int ft_isascii(int c);

Checks if a value belongs to the ASCII table.

---

	int ft_isprint(int c);

Checks if a character is printable.

---

	int ft_toupper(int c);

Converts a lowercase character into uppercase.

---

	int ft_tolower(int c);

Converts an uppercase character into lowercase.

---

**Memory Functions**

---

	void *ft_memset(void *s, int c, size_t n);

Fills a block of memory with a constant byte.

---

	void ft_bzero(void *s, size_t n);

Sets a memory area to zero.

---

	void *ft_memcpy(void *dest, const void *src, size_t n);

Copies memory from source to destination (no overlap allowed).

---

	void *ft_memmove(void *dest, const void *src, size_t n);

Copies memory safely even if regions overlap.

---

	void *ft_memchr(const void *s, int c, size_t n);

Searches for a byte inside memory.

---

	int ft_memcmp(const void *s1, const void *s2, size_t n);

Compares two memory areas.

---

	void *ft_calloc(size_t count, size_t size);

Allocates memory and initializes it to zero.

---

**String Functions**

---

	size_t ft_strlen(const char *s);

Returns the length of a string.

---

	char *ft_strdup(const char *s);

Allocates and duplicates a string.

---

	size_t ft_strlcpy(char *dst, const char *src, size_t size);

Copies a string safely into a buffer.

---

	size_t ft_strlcat(char *dst, const char *src, size_t size);

Appends a string safely to another string.

---

	char *ft_strchr(const char *s, int c);

Finds the first occurrence of a character.

---

	char *ft_strrchr(const char *s, int c);

Finds the last occurrence of a character.

---

	int ft_strncmp(const char *s1, const char *s2, size_t n);

Compares two strings up to n characters.

---

	char *ft_strnstr(const char *haystack, const char *needle, size_t len);

Searches for a substring inside another string.

---

	char *ft_substr(const char *s, unsigned int start, size_t len);

Creates a substring from a string.

---

	char *ft_strjoin(const char *s1, const char *s2);

Joins two strings into a new allocated string.

---

	char *ft_strtrim(const char *s1, const char *set);

Removes characters from the beginning and end.

---

	char **ft_split(const char *s, char c);

Splits a string into an array using a delimiter.

---

	char *ft_strmapi(const char *s, char (*f)(unsigned int, char));

Creates a new string by applying a function to each character.

---

	void ft_striteri(char *s, void (*f)(unsigned int, char*));

Applies a function to each character directly.

---

**Conversion Functions**

---

	int ft_atoi(const char *str);

Converts a string into an integer.

---

	char *ft_itoa(int n);

Converts an integer into a string.

---

**File Descriptor Output Functions**

---

	void ft_putchar_fd(char c, int fd);

Writes a character to a file descriptor.

---

	void ft_putstr_fd(const char *s, int fd);

Writes a string to a file descriptor.

---

	void ft_putendl_fd(const char *s, int fd);

Writes a string followed by a newline.

---

	void ft_putnbr_fd(int n, int fd);

Writes an integer to a file descriptor.

---

**Bonus — Linked List Functions**

---

	t_list *ft_lstnew(void *content);

Creates a new linked list node.

---

	void ft_lstadd_front(t_list **lst, t_list *new);

Adds a node at the beginning of the list.

---

	int ft_lstsize(t_list *lst);

Counts nodes in a list.

---

	t_list *ft_lstlast(t_list *lst);

Returns the last node.

---

	void ft_lstadd_back(t_list **lst, t_list *new);

Adds a node at the end.

---

	void ft_lstdelone(t_list *lst, void (*del)(void *));

Deletes one node safely.

---

	void ft_lstclear(t_list **lst, void (*del)(void *));

Deletes an entire list.

---

	void ft_lstiter(t_list *lst, void (*f)(void *));

Applies a function to every node.

---

	t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

Creates a new list by transforming content.

---

# get_next_line

`get_next_line` is a function that reads a file descriptor line by line.  
Each call returns the next available line from a file, standard input, or any readable file descriptor.

This project is part of the 42 Network curriculum and focuses on:

- File descriptor management
- Static variables
- Dynamic memory allocation
- Buffer handling
- Efficient reading using `read()`

---

## Features

✅ Reads one line at a time  
✅ Works with files, pipes, and standard input  
✅ Supports configurable buffer size  
✅ Memory-safe when correctly used  
✅ Compatible with multiple BUFFER_SIZE values

---

## How It Works

The function reads data from a file descriptor using a buffer of size BUFFER_SIZE.

A static memory area (stash) keeps unread content between function calls.

Each call:
	1.	Reads from the file descriptor until a newline (\n) or EOF is found.
	2.	Extracts the next line.
	3.	Saves remaining content for the next call.

---

## Usage Example

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("file.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
```

---

## Function Prototypes and Usage

⸻

**Mandatory Function**

	char *get_next_line(int fd);

Reads from a file descriptor and returns the next line including the newline character if present. Call repeatedly inside a loop until the function returns NULL.

⸻

**Internal Helper Functions (Utils)**

⸻

	size_t ft_gnl_strlen(const char *s);

Returns the length of a string. Used internally to safely calculate allocation sizes during concatenation operations.

⸻

	char *ft_gnl_strchr(const char *s, int c);

Searches for the first occurrence of a character inside a string. Used to detect newline characters and determine when a complete line has been read.

⸻

	char *ft_gnl_strjoin(char *s1, const char *s2);

Joins two strings into a newly allocated string. The first string is freed after joining. Used to append newly read buffer content into the stash.

⸻

	char *ft_gnl_getline(const char *stash);

Extracts a single line from the stored buffer content. Allocates and returns the next readable line.

⸻

	char *ft_gnl_newstash(char *stash);

Removes the extracted line from the stash and keeps only the remaining unread content for future calls.

⸻

## Return Values

get_next_line returns:
	•	A valid allocated string → next line successfully read.
	•	NULL → End of file reached or an error occurred.

The returned string must always be freed by the caller.

⸻

## Memory Management

Every returned line is dynamically allocated.

Example:

char *line = get_next_line(fd);
free(line);

Failure to free returned lines will cause memory leaks.

⸻

## Supported Inputs
	•	Regular files
	•	Standard input (fd = 0)
	•	Pipes
	•	Redirected streams

⸻

## Bonus Part (Concept)

The bonus version supports multiple file descriptors simultaneously.

Example:

fd1 -> file A
fd2 -> file B
fd1 -> file A again

Each descriptor keeps its own independent reading state.

⸻

## Common Tests

Test different buffer sizes:
```bash
-D BUFFER_SIZE=1
-D BUFFER_SIZE=42
-D BUFFER_SIZE=9999
```
Also test:
	•	Empty files
	•	Files without newline at EOF
	•	Very large files
	•	Alternating file descriptors (bonus)

---

# ft_printf — Custom printf Implementation

## Overview

ft_printf is a reimplementation of the standard C printf function.
The goal of this project is to understand variadic functions, formatted output, and low-level writing using the write system call.

This version implements the mandatory part of the project, supporting the following conversions:

	%c %s %p %d %i %u %x %X %%

The function writes formatted output to the standard output (stdout) and returns the total number of characters printed.

⸻

## Installation

You can link it to your project:
```bash
	cc main.c -L. -lftprintf
```
⸻

## Usage

Include the header:
```c
	#include "ft_printf.h"
```
Example:
```c
	ft_printf("Hello %s! Number = %d\n", "world", 42);
```
⸻

## Functions Documentation

Below are all implemented functions used in the mandatory part of ft_printf.

---

**Core Function**

⸻

	int ft_printf(const char *format, ...);

How to use it:
Main formatted output function. Pass a format string followed by a variable number of arguments. Each conversion specifier determines how the corresponding argument is printed.

Example:

	ft_printf("Value = %d\n", 10);

⸻

**Character Printer**

	int ft_print_char(char c);

How to use it:
Prints a single character to standard output using write. Usually called internally when %c is detected.

Example:

	ft_print_char('A');

---

**String Printer**

	int ft_print_str(const char *s);

How to use it:
Prints a string to standard output. If the pointer is NULL, the function prints (null) to mimic the behavior of the standard printf.

Example:

	ft_print_str("Hello");

⸻

**Pointer Printer**

	int ft_print_ptr(void *ptr);

How to use it:
Prints a memory address in hexadecimal format with the 0x prefix. If the pointer is NULL, (nil) is printed.

Example:

	int x;
	ft_print_ptr(&x);

⸻

**Signed Integer Printer**

	int ft_print_int(int n);

How to use it:
Prints a signed decimal integer. Negative numbers include a leading minus sign.

Example:

	ft_print_int(-42);

⸻

**Unsigned Integer Printer**

	int ft_print_uint(unsigned int n);

How to use it:
Prints an unsigned decimal number.

Example:

	ft_print_uint(42);

⸻

**Hexadecimal Printer**

	int ft_print_hex(unsigned int n, int uppercase);

How to use it:
Prints a number in hexadecimal format.
Set uppercase to:
	•	0 → lowercase (abcdef)
	•	1 → uppercase (ABCDEF)

Example:

	ft_print_hex(255, 0); // ff
	ft_print_hex(255, 1); // FF

⸻

**Percent Printer**

	int ft_print_percent(void);

How to use it:
Prints a literal percent character %. Used internally for the %% conversion.

Example:

	ft_print_percent();

⸻

## Return Value

All printing functions return:
	•	The number of characters successfully written.
	•	-1 if a write error occurs.

ft_printf returns the total number of printed characters.

⸻

## Allowed Functions

This project uses only the allowed external functions:
	•	write
	•	read
	•	malloc
	•	free
	•	va_start
	•	va_arg
	•	va_copy
	•	va_end

⸻

# Notes
	•	No buffer management is implemented (as required by the subject).
	•	All output is written directly to file descriptor 1 (stdout).
	•	Designed to be reusable in future projects.

⸻

# License

Educational project developed as part of the 42 curriculum.
