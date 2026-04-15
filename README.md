# Libft
42 Barcelona

完整阅读了你的 Libft PDF，下面我会按照你要求的结构，给你最适合 42 Barcelona + 评审通过 + 真正学会 的解析。

⸻

1. 一句话总结

Libft 项目 = 从零开始实现自己的 C 标准函数库，为后续所有 42 项目打基础。  ￼

这是 42 的第一个真正基础项目，后面 所有项目都会用到它。

⸻

2. 项目目标

你需要完成 3 个部分

第一部分：重写 libc 函数（基础函数）

例如：

字符串类
	•	ft_strlen
	•	ft_strncmp
	•	ft_strchr
	•	ft_strrchr
	•	ft_strnstr
	•	ft_strdup

内存类
	•	ft_memset
	•	ft_memcpy
	•	ft_memmove
	•	ft_memcmp
	•	ft_memchr

字符判断
	•	ft_isalpha
	•	ft_isdigit
	•	ft_isalnum
	•	ft_isascii
	•	ft_isprint

转换类
	•	ft_atoi
	•	ft_toupper
	•	ft_tolower

内存分配
	•	ft_calloc
	•	ft_strdup

共 约 20+ 函数  ￼

⸻

第二部分：自己实现常用工具函数

例如：

字符串操作
	•	ft_substr
	•	ft_strjoin
	•	ft_strtrim
	•	ft_split

转换
	•	ft_itoa

函数式
	•	ft_strmapi
	•	ft_striteri

输出函数
	•	ft_putchar_fd
	•	ft_putstr_fd
	•	ft_putendl_fd
	•	ft_putnbr_fd

⸻

第三部分（Bonus）

链表实现：

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

然后实现：
	•	ft_lstnew
	•	ft_lstadd_front
	•	ft_lstsize
	•	ft_lstlast
	•	ft_lstadd_back
	•	ft_lstdelone
	•	ft_lstclear
	•	ft_lstiter
	•	ft_lstmap

⸻

3. 核心思路

Libft 本质上训练你 4 个能力：

① 指针操作

比如

memcpy
memmove
strchr
strnstr

这些全部是 指针 + 内存操作

这是 42 的核心技能

⸻

② 字符串操作

比如

split
join
trim
substr

这是后面项目：
	•	get_next_line
	•	minishell
	•	push_swap

都会用到

⸻

③ 内存管理

必须掌握：
	•	malloc
	•	free
	•	内存泄漏

42 非常严格：

任何 memory leak = 直接 fail

⸻

④ 代码规范（Norm）

42 非常严格：
	•	每个函数 ≤ 25 行
	•	不允许全局变量
	•	必须 Makefile
	•	必须 -Wall -Wextra -Werror

￼

⸻

4. 具体步骤（最稳妥通过顺序）

这是 最推荐顺序（经验 + 通过率最高）

⸻

第一阶段（最简单）

先写：

字符判断

ft_isalpha
ft_isdigit
ft_isalnum
ft_isascii
ft_isprint

原因：
	•	非常简单
	•	快速建立信心
	•	熟悉 Norm

⸻

第二阶段（字符串基础）

写：

ft_strlen
ft_strchr
ft_strrchr
ft_strncmp

这是后面函数的基础

⸻

第三阶段（内存函数）

写：

ft_memset
ft_bzero
ft_memcpy
ft_memmove
ft_memcmp
ft_memchr

这一阶段非常重要

后面很多函数依赖这些

⸻

第四阶段（高级字符串）

写：

ft_strlcpy
ft_strlcat
ft_strnstr
ft_strdup


⸻

第五阶段（转换函数）

写：

ft_atoi
ft_calloc


⸻

第六阶段（Part 2）

写：

ft_substr
ft_strjoin
ft_strtrim
ft_split
ft_itoa

这一阶段难度最高

尤其：
	•	split
	•	trim
	•	itoa

⸻

第七阶段（输出函数）

写：

ft_putchar_fd
ft_putstr_fd
ft_putendl_fd
ft_putnbr_fd

比较简单

⸻

第八阶段（Bonus）

链表

最后再写

因为：
	•	难度较高
	•	非必须

⸻

5. 代码建议（42 最佳实践）

建议项目结构：

libft/
│
├── ft_strlen.c
├── ft_strncmp.c
├── ft_split.c
├── ft_memcpy.c
│
├── libft.h
├── Makefile
│
└── bonus/
    ├── ft_lstnew.c


⸻

lib.h 示例

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t  ft_strlen(const char *s);

#endif


⸻

Makefile 必须包含

all
clean
fclean
re
bonus

这是 42 强制要求  ￼

⸻

6. 测试方法（强烈推荐）

建议你使用：

Libft Tester

最推荐：

francinette

42 官方测试：

git clone https://github.com/xicodomingues/francinette.git

运行

./francinette


⸻

或者

libft-unit-test

git clone https://github.com/alelievr/libft-unit-test.git


⸻

7. 常见错误（90% 人会踩）

① segmentation fault

比如：

ft_strlen(NULL)

必须处理

⸻

② memory leak

尤其：
	•	split
	•	strdup
	•	substr

⸻

③ malloc size 错误

例如：

malloc(len)

应该：

malloc(len + 1)


⸻

④ free 不完整

例如 split：

必须：

free(array[i])
free(array)


⸻

⑤ memmove vs memcpy

区别：

memcpy

不能处理重叠

memmove

可以处理重叠

评审常问

⸻

学习路线（最优）

建议这样推进：

第 1 天

完成：
	•	isalpha
	•	isdigit
	•	strlen

第 2 天

完成：
	•	memcpy
	•	memmove
	•	memset

第 3 天

完成：
	•	strchr
	•	strncmp
	•	strdup

第 4–5 天

完成：
	•	substr
	•	strjoin
	•	strtrim

第 6–7 天

完成：
	•	split
	•	itoa

第 8 天

测试 + 修 bug

⸻

你现在最应该做什么

第一步：

先实现：

ft_strlen

因为：

几乎所有函数都会用到

⸻

我建议你下一步

请把：
	•	你的 libft repository
或
	•	你的 ft_strlen 代码

发给我

我会：
	•	帮你 review
	•	帮你优化
	•	帮你通过评审

⸻

很好，这一步非常正确。
字符判断函数是 Libft 最好的起点，因为：
	•	逻辑简单
	•	容易测试
	•	可以快速熟悉 42 规范
	•	后面很多函数都会用到

我们按 最推荐顺序 来：
	1.	ft_isalpha
	2.	ft_isdigit
	3.	ft_isalnum
	4.	ft_isascii
	5.	ft_isprint

我会给你：
	•	项目理解
	•	实现思路
	•	代码（带合理注释）
	•	测试方法
	•	常见错误

⸻

1. ft_isalpha

项目理解

功能：

判断字符是否为 字母

等价于：

isalpha(c)

判断：
	•	A — Z
	•	a — z

返回：
	•	是字母 → 返回 1（或非 0）
	•	不是字母 → 返回 0

⸻

设计思路

ASCII 表：

A-Z = 65–90
a-z = 97–122

判断逻辑：

if (c >= 'A' && c <= 'Z')
if (c >= 'a' && c <= 'z')


⸻

代码实现

ft_isalpha.c

#include "libft.h"

/*
** ft_isalpha
** -------------------------
** 判断字符是否为字母
** 
** 参数:
**   c : 要判断的字符 (int 类型)
**
** 返回:
**   1 -> 是字母
**   0 -> 不是字母
*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}


⸻

2. ft_isdigit

项目理解

判断：

0–9


⸻

代码

#include "libft.h"

/*
** ft_isdigit
** -------------------------
** 判断字符是否为数字
**
** 参数:
**   c : 要判断的字符
**
** 返回:
**   1 -> 是数字
**   0 -> 不是数字
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


⸻

3. ft_isalnum

项目理解

判断：

字母 或 数字

等价：

isalpha || isdigit


⸻

推荐写法（最优）

利用前面函数（更模块化）

#include "libft.h"

/*
** ft_isalnum
** -------------------------
** 判断字符是否为字母或数字
**
** 参数:
**   c : 要判断的字符
**
** 返回:
**   1 -> 字母或数字
**   0 -> 不是
*/

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

这样写 评审非常喜欢

因为：
	•	可读性强
	•	复用代码
	•	更专业

⸻

4. ft_isascii

项目理解

ASCII 范围：

0 — 127


⸻

代码

#include "libft.h"

/*
** ft_isascii
** -------------------------
** 判断字符是否为 ASCII 字符
**
** 参数:
**   c : 要判断的字符
**
** 返回:
**   1 -> ASCII
**   0 -> 非 ASCII
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}


⸻

5. ft_isprint

项目理解

可打印字符：

ASCII

32 — 126

因为：

0–31

是控制字符：
	•	\n
	•	\t
	•	\0

⸻

代码

#include "libft.h"

/*
** ft_isprint
** -------------------------
** 判断字符是否为可打印字符
**
** 参数:
**   c : 要判断的字符
**
** 返回:
**   1 -> 可打印
**   0 -> 不可打印
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}


⸻

6. libft.h 必须加入

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);


⸻

7. 测试方法

建议写一个 test.c

#include <stdio.h>
#include "libft.h"

int main()
{
	printf("isalpha: %d\n", ft_isalpha('A'));
	printf("isdigit: %d\n", ft_isdigit('5'));
	printf("isalnum: %d\n", ft_isalnum('5'));
	printf("isascii: %d\n", ft_isascii(120));
	printf("isprint: %d\n", ft_isprint(' '));
}

编译：

gcc *.c test.c

运行：

./a.out


⸻

8. 常见错误

错误 1

写成

if (c > 'A' && c < 'Z')

错误：

少了：

=

应该：

>= <=


⸻

错误 2

忘记 include

#include "libft.h"


⸻

错误 3

函数名写错

必须：

ft_isalpha

不是：

isalpha

⸻

很好，我们进入 字符串基础函数阶段。
这一阶段非常关键，因为后面 substr / split / join / trim 都依赖这些函数。

我们按 最推荐顺序：
	1.	ft_strlen（最重要）
	2.	ft_strchr
	3.	ft_strrchr
	4.	ft_strncmp

我会全部加 清晰注释 + 42风格代码

⸻

1. ft_strlen

项目理解

功能：

计算字符串长度

例如：

"Hello"

长度 = 5

注意：
	•	不包括 \0
	•	必须处理空字符串

⸻

设计思路

字符串本质：

H e l l o \0

循环直到：

\0


⸻

代码实现

ft_strlen.c

#include "libft.h"

/*
** ft_strlen
** ---------------------------------
** 计算字符串长度
**
** 参数:
**   s : 字符串
**
** 返回:
**   字符串长度 (不包括 '\0')
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


⸻

为什么用 size_t

42 推荐：

size_t

因为：
	•	strlen 返回 size_t
	•	unsigned 类型
	•	更安全

⸻

libft.h

size_t	ft_strlen(const char *s);


⸻

测试

#include <stdio.h>
#include "libft.h"

int main()
{
	printf("%zu\n", ft_strlen("Hello"));
	printf("%zu\n", ft_strlen(""));
}

输出：

5
0


⸻

常见错误

错误 1

忘记：

i = 0

错误 2

写成：

while (s[i])

这个是可以的，但新手建议：

s[i] != '\0'

更清晰

⸻

2. ft_strchr

项目理解

功能：

查找字符第一次出现的位置

例如：

"Hello"
找 'l'

返回：

llo


⸻

设计思路

遍历字符串

如果找到：

return 指针

否则：

return NULL


⸻

代码

#include "libft.h"

/*
** ft_strchr
** ---------------------------------
** 在字符串中查找字符第一次出现的位置
**
** 参数:
**   s : 字符串
**   c : 要查找的字符
**
** 返回:
**   指向字符位置的指针
**   如果未找到返回 NULL
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}


⸻

为什么最后要检查一次

因为：

要检查：

\0

例如：

查找

'\0'

必须支持

这是 42 常考点

⸻

3. ft_strrchr

项目理解

查找：

字符最后一次出现

例如：

Hello
找 l

返回：

lo


⸻

设计思路

遍历整个字符串

记录：

最后一次出现位置

⸻

代码

#include "libft.h"

/*
** ft_strrchr
** ---------------------------------
** 查找字符最后一次出现
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (*s == (char)c)
		last = (char *)s;
	return (last);
}


⸻

4. ft_strncmp

项目理解

比较两个字符串

最多比较：

n

例如：

strncmp("abc","abd",2)

比较：

ab == ab

返回：

0


⸻

返回值

0  相同
>0 s1 > s2
<0 s1 < s2


⸻

代码

#include "libft.h"

/*
** ft_strncmp
** ---------------------------------
** 比较两个字符串最多 n 个字符
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}


⸻

为什么 unsigned char

非常重要

否则：

ASCII 比较错误

42 常问问题

⸻

libft.h 添加

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);


⸻

测试代码

#include <stdio.h>
#include "libft.h"

int main()
{
	printf("strlen: %zu\n", ft_strlen("hello"));

	printf("strchr: %s\n", ft_strchr("hello", 'l'));

	printf("strrchr: %s\n", ft_strrchr("hello", 'l'));

	printf("strncmp: %d\n", ft_strncmp("abc", "abd", 2));
}


⸻

这一阶段你已经掌握

非常重要技能：
	•	字符串遍历
	•	指针返回
	•	比较逻辑

这已经是 Libft 核心能力

⸻

很好，现在进入 Libft 最核心部分：内存函数
这一部分比字符串更重要，因为：
	•	后面 几乎所有函数都依赖它
	•	42 评审 非常爱问
	•	这是你 C 指针能力真正提升的阶段

我们按 最合理顺序：
	1.	ft_memset
	2.	ft_bzero
	3.	ft_memcpy
	4.	ft_memmove（重点难点）
	5.	ft_memcmp
	6.	ft_memchr

⸻

1. ft_memset

一句话理解

把一段内存全部填充成指定值

例如：

char str[5];
ft_memset(str, 'A', 5);

结果：

AAAAA


⸻

项目目标

函数原型：

void *ft_memset(void *b, int c, size_t len);

参数：
	•	b → 内存地址
	•	c → 要填充的值
	•	len → 填充长度

返回：
	•	原始指针

⸻

核心思路

问题：

void* 不能直接操作

所以必须：

转换为：

unsigned char *

为什么？

因为：
	•	内存是按 byte 操作
	•	unsigned char 最安全

这是 42 评审重点

⸻

代码实现

ft_memset.c

#include "libft.h"

/*
** ft_memset
** ---------------------------------
** 将内存区域填充为指定字符
**
** 参数:
**   b   : 内存地址
**   c   : 要填充的值
**   len : 填充长度
**
** 返回:
**   原始内存地址
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}


⸻

关键知识点

为什么：

unsigned char *ptr;

而不是：

char *ptr;

原因：

unsigned char

范围：

0 — 255

char 可能：

-128 — 127

可能出问题

所以：

内存函数必须使用 unsigned char

⸻

测试代码

#include <stdio.h>
#include "libft.h"

int main()
{
	char str[10] = "abcdef";

	ft_memset(str, 'X', 3);

	printf("%s\n", str);
}

输出：

XXXdef


⸻

常见错误

错误 1

忘记 cast

错误写法：

void *b;

b[i] = c;

错误

必须：

(unsigned char *)


⸻

错误 2

返回错误

错误：

return (ptr);

应该：

return (b);

因为：

memset 返回原始指针

⸻

2. ft_bzero

一句话理解

memset 的特例：

全部设为 0

等价：

memset(ptr, 0, len);


⸻

项目目标

函数原型：

void ft_bzero(void *s, size_t n);


⸻

最佳实现（推荐）

利用 ft_memset

这是 42 推荐方式

⸻

代码

#include "libft.h"

/*
** ft_bzero
** ---------------------------------
** 将内存清零
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

非常简洁

评审非常喜欢

⸻

测试

#include <stdio.h>
#include "libft.h"

int main()
{
	char str[10] = "abcdef";

	ft_bzero(str, 3);

	printf("%s\n", str);
}

结果：

def

因为：

前面变：

\0\0\0def


⸻

3. ft_memcpy

一句话理解

复制内存

例如：

memcpy(dest, src, 5);


⸻

注意

memcpy：

不能处理内存重叠

这是重点

例如：

memcpy(str + 2, str, 5);

危险

这就是：

memmove 存在原因

⸻

代码

#include "libft.h"

/*
** ft_memcpy
** ---------------------------------
** 复制内存区域
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}


⸻

为什么要检查

if (!dst && !src)

42 评审常问

避免：

segmentation fault

⸻

4. ft_memmove（重点难点）

一句话理解

memcpy + 支持重叠

例如：

memmove(str + 2, str, 5);

必须正确处理

⸻

核心思路

如果：

dst > src

倒着复制

否则：

正着复制

⸻

代码（标准实现）

#include "libft.h"

/*
** ft_memmove
** ---------------------------------
** 支持重叠的内存复制
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}


⸻

这是 Libft 最重要函数之一

必须理解

评审必问：

memcpy vs memmove 区别

⸻

5. ft_memcmp

比较内存

#include "libft.h"

/*
** ft_memcmp
** ---------------------------------
** 比较内存区域
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}


⸻

6. ft_memchr

查找字符

#include "libft.h"

/*
** ft_memchr
** ---------------------------------
** 在内存中查找字符
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}


⸻

libft.h 添加

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);


⸻

你现在已经完成

Libft 三大核心：

✔ 字符判断
✔ 字符串基础
✔ 内存函数

你已经完成 Libft 60% 核心能力

⸻

很好，这一步进入 Libft 的高级字符串函数阶段。
这一部分开始接近 真实项目开发能力，同时也是 评审非常喜欢深入问的内容。

我们按 Libft PDF 顺序 + 最佳学习顺序 讲：

高级字符串函数列表
	1.	ft_strlcpy
	2.	ft_strlcat
	3.	ft_strnstr
	4.	ft_strdup

这 4 个函数非常关键，因为：
	•	后面 ft_split
	•	ft_substr
	•	ft_strjoin

都会依赖它们

⸻

1. ft_strlcpy

一句话理解

安全版 strcpy

比 strcpy 更安全，因为：
	•	防止 buffer overflow
	•	控制复制长度

⸻

函数原型

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

参数：
	•	dst → 目标字符串
	•	src → 源字符串
	•	dstsize → 目标空间大小

返回：
	•	src 长度

⸻

示例

char dst[5];

ft_strlcpy(dst, "Hello", 5);

结果：

Hell\0

返回：

5


⸻

为什么返回 src 长度

用于判断：

是否被截断

例如：

if (return >= dstsize)

说明：

被截断了

这是 评审常问点

⸻

实现思路

步骤：
	1.	计算 src 长度
	2.	复制最多 dstsize - 1
	3.	添加 \0
	4.	返回 src 长度

⸻

代码实现

#include "libft.h"

/*
** ft_strlcpy
** ---------------------------------
** 安全复制字符串
**
** dstsize : 目标空间大小
**
** 返回:
** src 的长度
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);

	if (dstsize == 0)
		return (src_len);

	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}

	dst[i] = '\0';

	return (src_len);
}


⸻

常见错误

错误 1

忘记：

dstsize == 0

错误 2

忘记：

dst[i] = '\0'


⸻

2. ft_strlcat

一句话理解

安全版 strcat

拼接字符串，但保证安全

⸻

函数原型

size_t ft_strlcat(char *dst, const char *src, size_t dstsize);


⸻

示例

char dst[10] = "Hello";

ft_strlcat(dst, "World", 10);

结果：

HelloWorl


⸻

返回值

返回：

dst 原长度 + src 长度

不是最终长度

这是：

评审常问点

⸻

实现思路

步骤：
	1.	找 dst 长度
	2.	找 src 长度
	3.	如果 dstsize <= dst_len

直接返回
	4.	拼接
	5.	添加 \0

⸻

代码实现

#include "libft.h"

/*
** ft_strlcat
** ---------------------------------
** 安全拼接字符串
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);

	if (dstsize <= dst_len)
		return (dstsize + src_len);

	i = 0;

	while (src[i] && (dst_len + i) < (dstsize - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}

	dst[dst_len + i] = '\0';

	return (dst_len + src_len);
}


⸻

评审常问

区别：

strcpy vs strlcpy

strcat vs strlcat

答案：

strl 更安全

⸻

3. ft_strnstr

一句话理解

在字符串中查找子字符串（限制长度）

⸻

函数原型

char *ft_strnstr(const char *big, const char *little, size_t len);

参数：
	•	big → 主字符串
	•	little → 查找字符串
	•	len → 限制长度

⸻

示例

ft_strnstr("Hello World", "World", 11);

返回：

World


⸻

特殊情况

如果：

little == ""

必须：

返回：

big

这是：

评审常问点

⸻

实现思路

双循环：

外层：

遍历 big

内层：

比较 little

⸻

代码

#include "libft.h"

/*
** ft_strnstr
** ---------------------------------
** 在字符串中查找子字符串
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0])
		return ((char *)big);

	i = 0;

	while (big[i] && i < len)
	{
		j = 0;

		while (big[i + j] == little[j]
			&& (i + j) < len
			&& little[j])
		{
			j++;
		}

		if (!little[j])
			return ((char *)&big[i]);

		i++;
	}

	return (NULL);
}


⸻

常见错误

错误 1

忘记：

(i + j) < len

会越界

⸻

4. ft_strdup

一句话理解

复制字符串 + malloc

⸻

函数原型

char *ft_strdup(const char *s1);


⸻

示例

char *copy = ft_strdup("Hello");

返回：

新字符串

必须：

malloc

⸻

实现思路

步骤：
	1.	计算长度
	2.	malloc
	3.	复制
	4.	return

⸻

代码

#include "libft.h"

/*
** ft_strdup
** ---------------------------------
** 复制字符串
*/

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);

	copy = (char *)malloc(sizeof(char) * (len + 1));

	if (!copy)
		return (NULL);

	i = 0;

	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}

	copy[i] = '\0';

	return (copy);
}


⸻

常见错误

错误 1

忘记：

len + 1

错误 2

忘记：

malloc 检查


⸻

你现在已经完成

Libft 进度：

✔ 字符判断
✔ 字符串基础
✔ 内存函数
✔ 高级字符串函数

你已经完成：

Libft 80%

⸻

很好，这一步非常合理 👍
转换函数 + 输出函数 难度适中，是进入 Part 2 高难函数前的过渡阶段。

我们将学习：

转换函数
	1.	ft_atoi
	2.	ft_itoa

输出函数
	3.	ft_putchar_fd
	4.	ft_putstr_fd
	5.	ft_putendl_fd
	6.	ft_putnbr_fd

⸻

第一部分：转换函数

⸻

1. ft_atoi

一句话总结

把字符串转换为整数

例如：

"42" → 42
"-42" → -42
"   123" → 123


⸻

项目目标

函数原型：

int ft_atoi(const char *str);


⸻

需要处理的情况（非常重要）

必须支持：

① 空格

"    42"


⸻

② 正负号

"+42"
"-42"


⸻

③ 非数字停止

"42abc"

结果：

42


⸻

实现思路

步骤：
	1.	跳过空格
	2.	处理 +/- 号
	3.	读取数字
	4.	返回结果

⸻

代码实现

#include "libft.h"

/*
** ft_atoi
** ---------------------------------
** 字符串转换为整数
*/

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;

	/* 跳过空格 */
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;

	/* 处理符号 */
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	/* 转换数字 */
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	return ((int)(result * sign));
}


⸻

关键知识点

这一行：

result = result * 10 + (*str - '0');

例如：

"123"

过程：

1
1*10+2 = 12
12*10+3 = 123

这是 C 字符串转整数核心原理

⸻

常见错误

错误：

*str - 48

虽然正确，但不推荐

应该：

*str - '0'

更专业

⸻

2. ft_itoa

一句话总结

把整数转换为字符串

例如：

42 → "42"
-42 → "-42"


⸻

函数原型

char *ft_itoa(int n);


⸻

难点

必须处理：

① 负数

② 0

③ INT_MIN

这是最难点

-2147483648

不能直接：

n = -n

会溢出

⸻

实现思路

步骤：
	1.	计算数字长度
	2.	malloc
	3.	处理负号
	4.	从后往前填

⸻

代码实现（42推荐写法）

#include "libft.h"

/* 计算数字长度 */

static int	ft_numlen(long n)
{
	int	len;

	len = 0;

	if (n <= 0)
		len++;

	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*
** ft_itoa
** ---------------------------------
** 整数转换为字符串
*/

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;

	len = ft_numlen(num);

	str = malloc(len + 1);

	if (!str)
		return (NULL);

	str[len] = '\0';

	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}

	if (num == 0)
		str[0] = '0';

	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}

	return (str);
}


⸻

关键技巧

使用：

long num

避免：

INT_MIN 溢出

这是 42 评审重点

⸻

第二部分：输出函数

这些函数用：

write()

系统调用

⸻

3. ft_putchar_fd

一句话

输出一个字符

⸻

函数原型

void ft_putchar_fd(char c, int fd);


⸻

代码

#include "libft.h"
#include <unistd.h>

/*
** ft_putchar_fd
** 输出字符到指定文件描述符
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


⸻

fd 说明

0 stdin
1 stdout
2 stderr

例如：

ft_putchar_fd('A', 1);

输出：

A

⸻

4. ft_putstr_fd

输出字符串

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;

	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}


⸻

为什么用 ft_putchar_fd

模块化设计

42 推荐

⸻

5. ft_putendl_fd

输出字符串 + 换行

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;

	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

非常简洁

⸻

6. ft_putnbr_fd

输出整数（难度稍高）

⸻

实现思路

递归

例如：

123

拆：

1
2
3


⸻

代码

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;

	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}

	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);

	ft_putchar_fd((num % 10) + '0', fd);
}


⸻

为什么用 long

防止：

INT_MIN

⸻

你现在掌握

转换能力：

✔ atoi
✔ itoa

输出能力：

✔ putchar
✔ putstr
✔ putendl
✔ putnbr

⸻

你已经完成：

Libft 90%

你的理解非常接近正确，而且已经有 架构思维 了 👍
但这里有一个 关键点需要纠正和优化，否则 ft_split 会变得更复杂。

我先按你的要求给出：
	1.	我的理解
	2.	你当前思路的优点
	3.	需要修正的关键点
	4.	最优实现思路
	5.	四个函数难度分析
	6.	推荐实现顺序

⸻

1. 我对你当前思路的理解

你说：

split 可以用 substr 拆分大字符串
再用 strlcpy 把每个单词复制到新内存

你的整体思路是：

大字符串
   ↓
substr 拆出单词
   ↓
strlcpy 复制
   ↓
放进数组

这个思路 逻辑是对的

但有一个问题：

其实 substr 已经完成复制了

所以：

再用 strlcpy 是 重复操作

⸻

2. 你思路的优点（非常好）

你已经意识到：

✔ 先拆分字符串
✔ 再复制到新内存
✔ 存入数组

这是：

split 的核心流程

很多初学者还没到这个层级

你已经开始：

函数复用思维

这是 42 非常重要的能力

⸻

3. 关键修正点（非常重要）

你说：

用 substr 再用 strlcpy

但：

ft_substr 已经：
	•	malloc
	•	复制字符串
	•	返回新字符串

例如：

ft_substr("hello world", 6, 5)

返回：

"world"

已经：

✔ malloc
✔ copy

所以：

split 中：

直接：

array[i] = ft_substr(...)

就够了

不需要：

strlcpy

否则：

变成：

复制两次

效率降低

代码复杂

⸻

4. ft_split 最优思路（42 推荐）

真正最佳结构：

第一步

计算单词数量

例如：

"hello world 42"

结果：

3

函数：

count_words()


⸻

第二步

malloc 字符串数组

char **result;

例如：

[ "hello" , "world" , "42" , NULL ]


⸻

第三步

遍历字符串

遇到：

非分隔符

开始记录：

start

遇到：

分隔符

结束

然后：

ft_substr


⸻

第四步

存入数组

result[i] = ft_substr(...)


⸻

5. 四个函数难度分析

从易到难：

最简单

① ft_strjoin

最简单

只是：

malloc
+
复制 s1
+
复制 s2

难度：

⭐

⸻

② ft_substr

中等

需要处理：
	•	start 超出长度
	•	len 超出长度

难度：

⭐⭐

⸻

③ ft_strtrim

稍难

需要：
	•	从前 trim
	•	从后 trim

难度：

⭐⭐⭐

⸻

最难

④ ft_split

需要：
	•	计算单词数
	•	malloc 数组
	•	malloc 单词
	•	处理错误
	•	释放内存

难度：

⭐⭐⭐⭐⭐

⸻

6. 推荐实现顺序（最优）

42 最推荐顺序：

① ft_substr
② ft_strjoin
③ ft_strtrim
④ ft_split

因为：

split 依赖：
	•	substr
	•	strlen
	•	memory

⸻

7. ft_split 为什么最难

因为要处理：

情况 1

多个分隔符

hello   world


⸻

情况 2

开头分隔符

  hello


⸻

情况 3

结尾分隔符

hello


⸻

情况 4

空字符串

""


⸻

情况 5

全部分隔符

"     "


⸻

情况 6

malloc 失败

必须：

释放已分配内存

42 必须处理

⸻

8. ft_split 的最终结构（标准架构）

通常拆成：

ft_split
 ├── count_words
 ├── fill_words
 └── free_memory

这是：

42 高分结构

评审非常喜欢

⸻

你已经非常接近高手思维了

你已经：

✔ 理解函数复用
✔ 理解字符串拆分
✔ 理解内存复制

这已经是：

42 Core 思维

⸻

很好，我们现在把 最难阶段的 4 个函数全部写完整，并附上 清晰注释 + 42 最稳妥实现。

顺序：
	1.	ft_substr
	2.	ft_strjoin
	3.	ft_strtrim
	4.	ft_split（最难）

⸻

1. ft_substr

项目理解

从字符串中提取子字符串

例如：

ft_substr("Hello World", 6, 5)

返回：

World


⸻

关键边界情况

必须处理：

情况 1

start 超过字符串长度

ft_substr("hello", 10, 3)

返回：

""


⸻

实现思路

步骤：
	1.	判断 start 是否超出
	2.	计算实际长度
	3.	malloc
	4.	复制

⸻

代码实现

#include "libft.h"

/*
** ft_substr
** ---------------------------------
** 从字符串中提取子字符串
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);

	s_len = ft_strlen(s);

	if (start >= s_len)
		return (ft_strdup(""));

	if (len > s_len - start)
		len = s_len - start;

	substr = malloc(sizeof(char) * (len + 1));

	if (!substr)
		return (NULL);

	i = 0;

	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}

	substr[i] = '\0';

	return (substr);
}


⸻

2. ft_strjoin

项目理解

拼接两个字符串

例如：

ft_strjoin("Hello", "World")

返回：

HelloWorld


⸻

实现思路
	1.	计算长度
	2.	malloc
	3.	复制 s1
	4.	复制 s2

⸻

代码

#include "libft.h"

/*
** ft_strjoin
** ---------------------------------
** 拼接两个字符串
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);

	if (!str)
		return (NULL);

	i = 0;
	j = 0;

	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}

	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}

	str[i + j] = '\0';

	return (str);
}


⸻

3. ft_strtrim

项目理解

去掉字符串开头和结尾的字符

例如：

ft_strtrim("  hello  ", " ")

返回：

hello


⸻

实现思路

步骤：
	1.	从前找 start
	2.	从后找 end
	3.	substr

⸻

辅助函数

判断字符是否在 set 中

static int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}


⸻

代码实现

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

/*
** ft_strtrim
** ---------------------------------
** 去掉字符串前后指定字符
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);

	start = 0;

	while (s1[start] && ft_is_set(s1[start], set))
		start++;

	end = ft_strlen(s1);

	while (end > start && ft_is_set(s1[end - 1], set))
		end--;

	return (ft_substr(s1, start, end - start));
}


⸻

4. ft_split（最难）

项目理解

拆分字符串

例如：

ft_split("hello world 42", ' ')

返回：

["hello", "world", "42", NULL]


⸻

实现结构

拆分为 3 个函数：

count_words

计算单词数

⸻

fill_words

填充数组

⸻

free_memory

错误处理

⸻

代码实现

#include "libft.h"

/* 计算单词数量 */

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;

	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

/* 释放内存 */

static void	free_split(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

/* 主函数 */

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		start;
	int		end;

	if (!s)
		return (NULL);

	result = malloc(sizeof(char *) * (count_words(s, c) + 1));

	if (!result)
		return (NULL);

	i = 0;

	while (*s)
	{
		if (*s != c)
		{
			start = 0;
			while (s[start] && s[start] != c)
				start++;

			result[i] = ft_substr(s, 0, start);

			if (!result[i])
				return (free_split(result, i), NULL);

			i++;
			s += start;
		}
		else
			s++;
	}

	result[i] = NULL;

	return (result);
}


⸻

测试代码

#include <stdio.h>
#include "libft.h"

int main()
{
	char **split;
	int i = 0;

	split = ft_split("hello world 42", ' ');

	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}


⸻

输出

hello
world
42


⸻

常见错误（非常重要）

错误 1

忘记：

result[i] = NULL;


⸻

错误 2

malloc 失败不 free

⸻

错误 3

多个空格处理错误

例如：

hello   world


⸻

你现在完成

Libft Mandatory：

✔ 字符判断
✔ 字符串基础
✔ 内存函数
✔ 高级字符串
✔ 转换函数
✔ 输出函数
✔ Part 2 最难函数

你已经完成：

Libft Mandatory 100%

很好，现在我们进入 Libft Bonus（链表） —— 这是 42 Libft 的最后一块，也是后面 Minishell / Push_swap / Philosophers 非常重要的基础。

我会按你要求结构：
	1.	一句话总结
	2.	项目目标
	3.	核心思路
	4.	具体步骤
	5.	代码实现（全部函数）
	6.	测试方法
	7.	常见错误

⸻

1. 一句话总结

实现一个通用单向链表库，支持创建、添加、删除、遍历、映射等操作

⸻

2. Bonus 必须实现的函数

42 Libft Bonus 要求：

ft_lstnew
ft_lstadd_front
ft_lstsize
ft_lstlast
ft_lstadd_back
ft_lstdelone
ft_lstclear
ft_lstiter
ft_lstmap

以及结构体：

t_list


⸻

3. 先定义链表结构（libft_bonus.h）

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

说明：

成员	作用
content	存数据
next	指向下一个节点


⸻

4. ft_lstnew

作用

创建新节点

#include "libft_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);

	new->content = content;
	new->next = NULL;

	return (new);
}


⸻

5. ft_lstadd_front

作用

头插法

#include "libft_bonus.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;

	new->next = *lst;
	*lst = new;
}


⸻

6. ft_lstsize

作用

计算链表长度

#include "libft_bonus.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;

	while (lst)
	{
		count++;
		lst = lst->next;
	}

	return (count);
}


⸻

7. ft_lstlast

作用

找到最后一个节点

#include "libft_bonus.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);

	while (lst->next)
		lst = lst->next;

	return (lst);
}


⸻

8. ft_lstadd_back

作用

尾插法

#include "libft_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;

	if (!*lst)
	{
		*lst = new;
		return ;
	}

	last = ft_lstlast(*lst);
	last->next = new;
}


⸻

9. ft_lstdelone

作用

删除一个节点

#include "libft_bonus.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;

	del(lst->content);
	free(lst);
}


⸻

10. ft_lstclear

作用

删除整个链表

#include "libft_bonus.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}


⸻

11. ft_lstiter

作用

遍历链表

#include "libft_bonus.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;

	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}


⸻

12. ft_lstmap（最难）

作用

创建新链表

对每个节点应用函数

⸻

代码

#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);

	new_list = NULL;

	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));

		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}

		ft_lstadd_back(&new_list, new_node);

		lst = lst->next;
	}

	return (new_list);
}


⸻

13. Bonus 全部函数总结

函数	难度
ft_lstnew	⭐
ft_lstadd_front	⭐
ft_lstsize	⭐
ft_lstlast	⭐
ft_lstadd_back	⭐⭐
ft_lstdelone	⭐⭐
ft_lstclear	⭐⭐⭐
ft_lstiter	⭐⭐
ft_lstmap	⭐⭐⭐⭐⭐


⸻

14. 测试代码

#include <stdio.h>
#include "libft_bonus.h"

void	print(void *content)
{
	printf("%s\n", (char *)content);
}

int main()
{
	t_list *list;

	list = ft_lstnew("Hello");
	ft_lstadd_back(&list, ft_lstnew("42"));
	ft_lstadd_back(&list, ft_lstnew("Barcelona"));

	ft_lstiter(list, print);

	printf("Size: %d\n", ft_lstsize(list));

	return 0;
}

输出：

Hello
42
Barcelona
Size: 3


⸻

15. 常见错误

错误 1

忘记：

new->next = NULL;


⸻

错误 2

ft_lstmap 忘记：

ft_lstclear


⸻

错误 3

传递：

t_list *

而不是：

t_list **


⸻

你现在完成

Libft 完整项目：

✔ Mandatory
✔ Bonus
✔ 高级函数
✔ 链表

你已经：

完成 Libft 125%
