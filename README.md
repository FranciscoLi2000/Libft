# Libft

一个可复用的 C 静态函数库，基于 42 Barcelona `libft` 项目规范实现，并扩展为可直接集成到日常 C 项目的基础工具包。

## 目录
- [项目概览](#项目概览)
- [特性](#特性)
- [项目结构](#项目结构)
- [环境要求](#环境要求)
- [快速开始](#快速开始)
- [API 说明](#api-说明)
  - [Part 1: libc 兼容函数](#part-1-libc-兼容函数)
  - [Part 2: 实用扩展函数](#part-2-实用扩展函数)
  - [Bonus: 链表函数](#bonus-链表函数)
- [与项目集成](#与项目集成)
- [测试与验证](#测试与验证)
- [代码规范](#代码规范)
- [许可证](#许可证)

## 项目概览

`libft` 是一个静态库（`libft.a`），提供：
- 常用字符/字符串/内存操作函数
- 常用转换与输出函数
- 链表数据结构与操作（Bonus）

该库可以作为后续 C 项目的基础依赖，减少重复造轮子，统一底层工具函数行为。

## 特性

- ✅ 使用 `Makefile` 一键构建
- ✅ 严格编译选项：`-Wall -Wextra -Werror`
- ✅ 明确头文件边界：`libft.h` 与 `libft_bonus.h`
- ✅ 模块化源码目录，便于维护和扩展
- ✅ 附带简单可执行示例：`test/main.c`

## 项目结构

```text
.
├── includes/
│   ├── libft.h
│   └── libft_bonus.h
├── src/                  # Part 1 + Part 2 函数实现
├── bonus/                # Bonus 链表函数实现
├── test/
│   └── main.c            # 本地快速验证示例
├── Makefile
└── README.md
```

## 环境要求

- C 编译器（推荐 `cc` / `clang` / `gcc`）
- `make`
- POSIX 环境（Linux/macOS）

## 快速开始

### 1) 构建基础库

```bash
make
```

### 2) 构建 Bonus（链表）

```bash
make bonus
```

### 3) 清理产物

```bash
make clean
make fclean
```

### 4) 在你的项目中链接

```bash
cc your_main.c -Iincludes -L. -lft -o your_app
```

## API 说明

### Part 1: libc 兼容函数

**字符判断与转换**
- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_toupper`
- `ft_tolower`

**字符串操作**
- `ft_strlen`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_strnstr`
- `ft_strdup`

**内存操作**
- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_calloc`

**数值转换**
- `ft_atoi`

### Part 2: 实用扩展函数

- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

**内部辅助函数（已暴露在头文件中）**
- `ft_is_set`
- `ft_numlen`

### Bonus: 链表函数

基于如下结构：

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

函数列表：
- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

## 与项目集成

推荐在其他项目中以子模块或直接源码依赖方式接入，并在构建流程中先执行：

```bash
make -C path/to/libft
```

然后在目标项目中添加：
- 头文件路径：`-I path/to/libft/includes`
- 链接路径：`-L path/to/libft`
- 链接库：`-lft`

## 测试与验证

仓库包含示例测试入口：`test/main.c`。

本地验证示例：

```bash
make re
make bonus
cc -Wall -Wextra -Werror test/main.c -Iincludes -L. -lft -o test/main
./test/main
```

你也可以按项目需要引入更完整的单元测试框架（例如 Criterion / CMocka）扩展测试覆盖率。

## 代码规范

- 遵循 42 常用规范与 C 代码风格要求
- 编译必须在 `-Wall -Wextra -Werror` 下通过
- 优先保证：
  - 边界条件正确
  - 内存分配失败处理
  - 无内存泄漏

## 许可证

本项目采用仓库内 `LICENSE` 文件所声明的许可证。
