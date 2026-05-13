# Libft

> Trilingual README / 三语说明 / README trilingüe  
> Languages: [中文](#中文) · [English](#english) · [Español](#español)

---

## 中文

### 项目简介
`libft` 是一个可复用的 C 静态函数库（`libft.a`），基于 42 的 Libft 项目实现，包含：
- libc 常见函数的自定义实现
- 常用字符串/内存/转换与输出工具函数
- Bonus 链表函数集合

适合作为后续 C 项目的基础依赖库，减少重复代码并统一底层行为。

### 目录结构
```text
.
├── includes/
│   ├── libft.h
│   └── libft_bonus.h
├── src/                  # Part 1 + Part 2
├── bonus/                # Bonus 链表函数
├── test/
│   └── main.c            # 示例测试入口
├── Makefile
└── README.md
```

### 环境要求
- C 编译器（`cc` / `clang` / `gcc`）
- `make`
- POSIX 环境（Linux / macOS）

### 快速开始
1. 构建基础库：
```bash
make
```

2. 构建 Bonus：
```bash
make bonus
```

3. 清理产物：
```bash
make clean
make fclean
```

4. 在你的项目中链接：
```bash
cc your_main.c -Iincludes -L. -lft -o your_app
```

### API 总览
**Part 1: libc 兼容函数**
- 字符判断与转换：`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- 字符串操作：`ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- 内存操作：`ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- 数值转换：`ft_atoi`

**Part 2: 实用扩展函数**
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- 辅助函数：`ft_is_set`, `ft_numlen`

**Bonus: 链表函数**
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

链表结构：
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

### 测试与验证
仓库提供示例测试：`test/main.c`

```bash
make re
make bonus
cc -Wall -Wextra -Werror test/main.c -Iincludes -L. -lft -o test/main
./test/main
```

### 代码规范
- 使用编译选项：`-Wall -Wextra -Werror`
- 重视边界条件、内存分配失败处理与内存安全

### 许可证
本项目使用仓库中 `LICENSE` 文件所声明的许可证。

---

## English

### Overview
`libft` is a reusable C static library (`libft.a`) based on the 42 Libft project. It provides:
- Custom reimplementations of common libc functions
- Utility functions for strings, memory, conversion, and output
- Bonus linked-list utilities

It is designed to be a foundational dependency for later C projects, reducing duplicated code and standardizing low-level behavior.

### Project Structure
```text
.
├── includes/
│   ├── libft.h
│   └── libft_bonus.h
├── src/                  # Part 1 + Part 2
├── bonus/                # Bonus linked-list functions
├── test/
│   └── main.c            # Sample test entry
├── Makefile
└── README.md
```

### Requirements
- C compiler (`cc` / `clang` / `gcc`)
- `make`
- POSIX environment (Linux / macOS)

### Quick Start
1. Build the base library:
```bash
make
```

2. Build bonus part:
```bash
make bonus
```

3. Clean build artifacts:
```bash
make clean
make fclean
```

4. Link it in your own project:
```bash
cc your_main.c -Iincludes -L. -lft -o your_app
```

### API Summary
**Part 1: libc-compatible functions**
- Character checks/conversion: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- String operations: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- Memory operations: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- Numeric conversion: `ft_atoi`

**Part 2: utility extensions**
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- Helper functions: `ft_is_set`, `ft_numlen`

**Bonus: linked-list functions**
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

List type:
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

### Testing
The repository includes a sample test entry: `test/main.c`

```bash
make re
make bonus
cc -Wall -Wextra -Werror test/main.c -Iincludes -L. -lft -o test/main
./test/main
```

### Coding Guidelines
- Build with strict flags: `-Wall -Wextra -Werror`
- Prioritize edge-case correctness, allocation-failure handling, and memory safety

### License
Licensed under the terms specified in the repository `LICENSE` file.

---

## Español

### Descripción general
`libft` es una biblioteca estática reutilizable en C (`libft.a`), basada en el proyecto Libft de 42. Incluye:
- Reimplementaciones de funciones comunes de libc
- Utilidades para cadenas, memoria, conversión y salida
- Funciones bonus para listas enlazadas

Está pensada como dependencia base para proyectos posteriores en C, reduciendo código duplicado y unificando comportamientos de bajo nivel.

### Estructura del proyecto
```text
.
├── includes/
│   ├── libft.h
│   └── libft_bonus.h
├── src/                  # Part 1 + Part 2
├── bonus/                # Funciones bonus de listas enlazadas
├── test/
│   └── main.c            # Entrada de prueba de ejemplo
├── Makefile
└── README.md
```

### Requisitos
- Compilador de C (`cc` / `clang` / `gcc`)
- `make`
- Entorno POSIX (Linux / macOS)

### Inicio rápido
1. Compilar la biblioteca base:
```bash
make
```

2. Compilar bonus:
```bash
make bonus
```

3. Limpiar artefactos:
```bash
make clean
make fclean
```

4. Enlazarla en tu proyecto:
```bash
cc your_main.c -Iincludes -L. -lft -o your_app
```

### Resumen de API
**Part 1: funciones compatibles con libc**
- Verificación/conversión de caracteres: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- Operaciones de cadena: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- Operaciones de memoria: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- Conversión numérica: `ft_atoi`

**Part 2: extensiones útiles**
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- Funciones auxiliares: `ft_is_set`, `ft_numlen`

**Bonus: funciones de listas enlazadas**
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

Tipo de lista:
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

### Pruebas
El repositorio incluye una prueba de ejemplo: `test/main.c`

```bash
make re
make bonus
cc -Wall -Wextra -Werror test/main.c -Iincludes -L. -lft -o test/main
./test/main
```

### Guía de código
- Compilar con flags estrictos: `-Wall -Wextra -Werror`
- Priorizar casos límite, manejo de fallos de memoria y seguridad de memoria

### Licencia
Este proyecto se distribuye bajo la licencia indicada en el archivo `LICENSE` del repositorio.
