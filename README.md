# 📚 Libft – Custom C Standard Library

Welcome to my implementation of `Libft`, the foundational project of the 42 curriculum. This project involved recreating essential functions from the C standard library, as well as developing additional utility functions. The goal was to deepen my understanding of C programming, memory management, and data structures.

---

## 📁 Repository Structure

Libft/
├── libft/ # Core library functions
├── lib_bonus/ # Bonus functions (linked list operations)
├── includes/ # Header files
├── exam_rank_2/ # Exam preparation exercises
├── Makefile # Build instructions
├── LICENSE # License information
├── README.md # Project documentation
└── en.Libft.pdf # Project subject PDF


---

## 🔧 Compilation and Usage

To compile the library, navigate to the `Libft` directory and run:
	```
	make
	```
This will generate a `libft.a` archive file.

To clean up object files:
	```
	make clean
	```

To remove all compiled files:
	```
	make fclean
	```

To recompile the library:
	```
	make re
	```

To include the library in your project:
```c
#include "libft.h"
```

Compile your project with:
```
gcc your_program.c libft.a -o your_program
```

## 🧠 Project Highlights

### Core Library (libft/)
Reimplementation of standard C functions, including:

Character checks: ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint

String operations: ft_strlen, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strncmp, ft_strdup, ft_substr, ft_strjoin, ft_strtrim, ft_split

Memory operations: ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp, ft_calloc

Case conversion: ft_toupper, ft_tolower

Conversion: ft_atoi, ft_itoa

Output functions: ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd

### Bonus Functions (lib_bonus/)
Implementation of singly linked list operations:

ft_lstnew, ft_lstadd_front, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap, ft_lstsize, ft_lstlast

### Exam Preparation (exam_rank_2/)
A collection of exercises to prepare for the 42 exams, focusing on algorithmic problem-solving and efficient coding practices.

## 📄 License
This project is licensed under the MIT License. See the LICENSE file for details.

## 📬 Contact
For any questions or feedback, feel free to reach out:
Email: liyufeng577@gmail.com

This project was completed as part of the 42 Barcelona curriculum.
```

Feel free to customize this `README.md` further to reflect your personal experiences and insights from the project. If you need assistance with any specific sections or have other questions, don't hesitate to ask!
::contentReference[oaicite:0]{index=0}
 
```
