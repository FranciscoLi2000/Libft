# Libft

A compact, well-documented README explaining how to use every function included in this repository: libft (mandatory and additional functions), get_next_line, and ft_printf. Each function has a short description and a minimal usage example.

⸻

## Table of contents
	•	About
	•	Build / Installation
	•	Libft — Mandatory (replacements for libc)
	•	Libft — Additional functions
	•	Bonus — Linked list helpers
	•	get_next_line
	•	ft_printf
	•	Notes & edge-cases
	•	Contributing
	•	License

⸻

## About

	This repository contains implementations of common C utility functions used in the 42 school projects:
	•	libft — reimplementations of useful libc functions plus helper utilities.
	•	get_next_line — read a file descriptor line-by-line.
	•	ft_printf — a mini printf supporting common specifiers.

	Use these functions as drop-in helpers in small C projects or as practice for systems programming fundamentals.

⸻

## Build / Installation

	Typical compilation with GCC (example to build a static library libft.a):
	`
	# compile object files
	gcc -Wall -Wextra -Werror -c src/*.c -I includes
	
	# create static archive
	ar rcs libft.a *.o
	
	# link into a program
	gcc -o myprog main.c libft.a

	Alternatively, include the src/ and includes/ in your Makefile and build as needed.

⸻

## Libft — Mandatory (replacements for libc)

	Below each prototype is a short description and a tiny example showing how to use it.

	`
	int ft_isalpha(int c);    // returns non-zero if c is alphabetic (a-z and A-Z)
	int ft_isdigit(int c);    // returns non-zero if c is digit (0-9)
	int ft_isalnum(int c);    // letter or digit
	int ft_isascii(int c);    // 0..127
	int ft_isprint(int c);    // printable (32..126)
	int ft_toupper(int c);    // convert to uppercase (if applicable)
	int ft_tolower(int c);    // convert to lowercase (if applicable)

	size_t  ft_strlen(const char *s);                    // string length
	void    *ft_memset(void *s, int c, size_t n);        // set n bytes to c
	void    ft_bzero(void *s, size_t n);                 // zero n bytes
	void    *ft_memcpy(void *dest, const void *src, size_t n); // copy n bytes
	void    *ft_memmove(void *dest, const void *src, size_t n); // safe copy
	void    *ft_memchr(const void *s, int c, size_t n);  // locate byte in memory
	int     ft_memcmp(const void *s1, const void *s2, size_t n); // compare memory
	char    *ft_strchr(const char *s, int c);            // first occurrence
	char    *ft_strrchr(const char *s, int c);           // last occurrence
	int     ft_strncmp(const char *s1, const char *s2, size_t n); // compare strings
	size_t  ft_strlcpy(char *dest, const char *src, size_t destsize); // safe copy
	size_t  ft_strlcat(char *dest, const char *src, size_t destsize); // safe concat
	char    *ft_strnstr(const char *haystack, const char *needle, size_t len); // find substring
	int     ft_atoi(const char *str);                    // ascii to int
	void    *ft_calloc(size_t count, size_t size);       // allocate zeroed memory
	char    *ft_strdup(const char *s);                   // duplicate string

⸻

### Libft — Additional functions

	`
	char    *ft_substr(const char *s, unsigned int start, size_t len);  // substring
	char    *ft_strjoin(const char *s1, const char *s2);               // join two strings
	char    *ft_strtrim(const char *s1, const char *set);              // trim set chars from ends
	char    **ft_split(const char *s, char c);                         // split by delimiter
	char    *ft_itoa(int n);                                           // int -> string
	char    *ft_strmapi(const char *s, char (*f)(unsigned int, char)); // map + return new string
	void    ft_striteri(char *s, void (*f)(unsigned int, char*));     // apply func in-place
	void    ft_putchar_fd(char c, int fd);                            // put char to fd
	void    ft_putstr_fd(const char *s, int fd);                      // put string to fd
	void    ft_putendl_fd(const char *s, int fd);                     // put string + '\n'
	void    ft_putnbr_fd(int n, int fd);                              // put integer to fd

	•	ft_split returns a NULL-terminated array; free each element then the array itself.
	•	ft_substr returns an allocated string; returns "" (empty string) for start >= strlen(s).

⸻

### Bonus — Linked list helpers

	Linked list struct:
	`
	typedef struct s_list
	{
		void            *content;
		size_t          content_size;
		struct s_list   *next;
	}	t_list;

	t_list  *ft_lstnew(void *content);
	void    ft_lstadd_front(t_list **lst, t_list *new);
	int     ft_lstsize(t_list *lst);
	t_list  *ft_lstlast(t_list *lst);
	void    ft_lstadd_back(t_list **lst, t_list *new);
	void    ft_lstdelone(t_list *lst, void (*del)(void *));
	void    ft_lstclear(t_list **lst, void (*del)(void *));
	void    ft_lstiter(t_list *lst, void (*f)(void *));
	t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

	•	ft_lstdelone frees a single node using del.
	•	ft_lstmap returns a new list where each node content is the result of f; del cleans if allocation fails.

⸻

## Get next line

	`
	char    *get_next_line(int fd);
	size_t  ft_gnl_strlen(const char *s);
	char    *ft_gnl_strchr(const char *s, int c);
	char    *ft_gnl_strjoin(char *s1, const char *s2);
	char    *ft_gnl_getline(const char *stash);
	char    *ft_gnl_newstash(char *stash);

	•	get_next_line manages an internal stash per fd. Free each line returned by the caller.
	•	Buffer size and behavior might depend on the BUFFER_SIZE macro — check repo settings.

⸻

## Printf

	`
	int	ft_printf(const char *format, ...);
	int	ft_print_char(char c);
	int	ft_print_str(const char *s);
	int	ft_print_ptr(void *ptr);
	int	ft_print_int(int n);
	int	ft_print_uint(unsigned int n);
	int	ft_print_hex(unsigned int n, int uppercase);
	int	ft_print_percent(void);

⸻

## Notes & edge-cases

	•	All functions that return char * or other heap memory allocate with malloc. Caller must free() them when no longer needed.
	•	Input validation: many functions expect non-NULL pointers; check behavior in edge-cases (e.g., NULL inputs, empty strings).
	•	For ft_strlcpy / ft_strlcat: follow standard semantics (returns total length of attempted result).
	•	For ft_split: consecutive delimiters are skipped; result is NULL-terminated.
	•	For get_next_line: if using multiple file descriptors concurrently, ensure implementation supports it (per 42 requirements).
	•	For ft_printf: behavior for unsupported format flags (width, precision, length modifiers) is not guaranteed — use supported specifiers only.

⸻

## Contributing

	If you want to improve tests, add more examples, or extend features:
	1.	Fork the repository.
	2.	Create a branch: feature/your-change.
	3.	Add tests/examples in examples/ or tests/.
	4.	Open a pull request with a short description.

⸻

## License

	Choose your license — for example, add an MIT or Unlicense file if you want this repo open-source. (No license file is included by default.)

