# 第16章 预处理器 核心内容

## 16.1 概述

C预处理器是编译过程中的第一阶段，负责在编译之前处理源代码中的预处理指令。预处理器的主要功能包括：
- 文件包含（#include）
- 宏定义和展开（#define, #undef）
- 条件编译（#if, #ifdef, #ifndef, #else, #elif, #endif）
- 错误处理和编译器指令（#error, #pragma, #line）

## 16.2 翻译阶段

在预处理之前，编译器会进行以下翻译处理：

1. **字符映射**：源字符集映射、三字符序列等
2. **行拼接**：反斜杠（\）+ 换行符合并为逻辑行
3. **词法切分**：划分为预处理记号、空白、注释
4. **预处理阶段**：查找并执行以#开头的预处理指令

## 16.3 #define 预处理器指令

### 16.3.1 明示常量（类对象宏）

#### 基本语法
```c
#define 名称 替换列表
```

#### 命名规则
- 只能使用字符、数字、下划线
- 首字符不能是数字

#### 替换与展开
- 预处理器进行文本替换（宏展开）
- 发生在编译之前，不做计算，只做文本替换

#### 注释与空格处理
- 每条注释被一个空格替换
- 替换列表中多个空格的处理取决于实现

#### 续行
```c
#define OW "Consistency is the last refuge of the unimagina\
tive.- Oscar Wilde"
```

#### 嵌套宏
```c
#define TWO 2
#define FOUR TWO TWO  // 展开为 TWO TWO，进一步展开为 2 2
```

#### 字符串中的宏
- 双引号内的宏名称不被替换
- 需要在引号外使用格式说明符打印

#### 数组大小与 const
```c
#define LIMIT 20
static int data1[LIMIT];  // 有效

const int LIM = 50;
static int data2[LIM];    // 在C中通常无效
```

#### 重定义常量
- 同一宏在同一作用域可重定义
- 新旧定义必须"完全相同"（记号序列相同）
- 建议用 #undef 旧定义后再 #define 新定义

### 16.3.2 类函数宏（带参数的宏）

#### 基本语法
```c
#define 名称(参数列表) 替换列表
```

#### 常见陷阱与正确写法

**优先级问题**
```c
// 错误写法
#define SQUARE(x) x x
SQUARE(x+2)  // 展开为 x+2 x+2，不是乘法

// 正确写法
#define SQUARE(x) ((x)*(x))
```

**参数多次求值**
```c
// 错误：副作用参数
SQUARE(++x)  // 可能变成 ++x ++x，未定义行为

// 建议：避免副作用参数
```

#### #运算符（字符串化运算符）
```c
#define PSQR(x) printf("The square of " #x " is %d.\n", ((x)*(x)))

// 调用 PSQR(y); 展开为：
// printf("The square of " "y" " is %d.\n", ((y)*(y)));
```

#### ##运算符（粘贴运算符）
```c
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x" #n " = %d\n", x##n);

// 使用示例
int XNAME(1) = 14;    // 变成 int x1 = 14;
PRINT_XN(1);          // 变成 printf("x1 = %d\n", x1);
```

#### 变参宏（C99/C11）
```c
#define PR(...) printf(__VA_ARGS__)

// 使用示例
PR("Howdy");
PR("weight = %d, shipping = $%.2f\n", wt, sp);
```

### 16.3.3 宏和函数的选择

#### 使用宏的优点
- 不担心变量类型（处理字符串而非实际值）
- 生成内联代码，执行速度更快
- 无调用开销

#### 使用宏的缺点
- 可能产生副作用
- 增加代码大小（每次调用都插入代码）
- 调试困难

#### 选择标准
```c
// 简单函数常用宏
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define ABS(X) ((X)<0?-(X):(X))
```

#### 使用建议
- 用圆括号包围宏参数和整个替换体
- 用大写字母表示宏函数名称
- 避免在宏中使用递增/递减运算符

## 16.4 文件包含 #include

### 16.4.1 两种形式
```c
#include <filename>   // 标准系统目录
#include "filename"  // 当前目录优先
```

### 16.4.2 工作原理
- 预处理器将文件内容插入到 #include 位置
- 相当于"复制-粘贴"操作
- 减少重复书写，提高可维护性

### 16.4.3 头文件示例

#### names_st.h
```c
// 常量
#define SLEN 32

// 结构声明
struct names_st {
    char first[SLEN];
    char last[SLEN];
};

// 类型定义
typedef struct names_st names;

// 函数原型
void get_names(names *pn);
void show_names(const names *pn);
char s_gets(char *st, int n);
```

#### 头文件常见内容
- 明示常量（EOF、NULL、BUFSIZE）
- 宏函数
- 函数声明
- 结构模板定义
- 类型定义

## 16.5 其他预处理指令

### 16.5.1 #undef 指令
```c
#define LIMIT 400
#undef LIMIT  // 取消之前的定义
```

### 16.5.2 条件编译

#### #ifdef、#else、#endif
```c
#ifdef MAVIS
    #include "horse.h"
    #define STABLES 5
#else
    #include "cow.h"
    #define STABLES 15
#endif
```

#### #ifndef（防止重复定义）
```c
#ifndef SIZE
    #define SIZE 100
#endif
```

#### 头文件防重复包含
```c
#ifndef NAMES_H
#define NAMES_H
// 头文件内容
#endif
```

#### #if、#elif、#else
```c
#if SYS == 1
    #include "ibmpc.h"
#elif SYS == 2
    #include "vax.h"
#elif SYS == 3
    #include "mac.h"
#else
    #include "general.h"
#endif
```

#### defined 运算符
```c
#if defined(VAX)
    #include "vax.h"
#elif defined(IBMPC)
    #include "ibmpc.h"
#else
    #include "general.h"
#endif
```

### 16.5.3 #line 和 #error 指令

#### #line 指令
```c
#define 1000        // 重置行号为1000
#define 10 "cool.c" // 重置行号为10，文件名为cool.c
```

#### #error 指令
```c
#if __STDC_VERSION__ != 201112L
    #error Not C11
#endif
```

### 16.5.4 #pragma 指令
```c
#pragma c9x on          // 启用C9X特性
#define PRAGMA(X) _Pragma(#X)
#define LIMRG(X) PRAGMA(STDC CX_LIMITED_RANGE X)
LIMRG(ON)              // 展开为 #pragma STDC CX_LIMITED_RANGE ON
```

## 16.6 预定义宏

| 宏 | 含义 |
|----|------|
| `__DATE__` | 预处理日期，格式为 "Mmm dd yyyy" |
| `__FILE__` | 当前源代码文件名 |
| `__LINE__` | 当前源代码行号 |
| `__STDC__` | 为1时表示遵循ISO C标准 |
| `__STDC_HOSTED__` | 本机环境为1，嵌入式为0 |
| `__STDC_VERSION__` | C99为199901L，C11为201112L |
| `__TIME__` | 翻译时间，格式为 "hh:mm:ss" |
| `__func__` | 函数名（不是宏，具有函数作用域） |

#### 使用示例
```c
void why_me() {
    printf("This function is %s\n", __func__);
}
```

## 16.7 C11 新特性

### 16.7.1 通用选择表达式（_Generic）

#### 基本语法
```c
#define MYTYPE(X) _Generic((X),\
        int:    "int",\
        float:  "float",\
        double: "double",\
        default: "other")

// 使用示例
printf("%s\n", MYTYPE(5));      // 输出：int
printf("%s\n", MYTYPE(2.0d));   // 输出：double
printf("%s\n", MYTYPE(&d));     // 输出：other
```

### 16.7.2 内联函数（C99）

#### 基本用法
```c
#include <stdio.h>

inline static void eatline(void) {
    while (getchar() != '\n')
        ;
}

int main(void) {
    eatline();  // 可能被直接展开
    return 0;
}
```

#### 注意事项
- 编译器可能忽略内联建议
- 函数应简短，以避免过长的内联代码
- 可以通过取函数地址创建非内联版本
- 支持将内联函数定义放入头文件（内部链接）

### 16.7.3 Noreturn 函数（C11）

#### 特点
- 表明函数不会返回主调程序
- 不同于 void 返回类型
- 用于编译器优化和错误预防

#### 示例
```c
_Noreturn void exit(int status);
```

## 16.8 C库概述

### 16.8.1 访问C库的方法

#### 1. 自动访问
- 许多系统自动提供常用库函数
- 只需编译即可使用

#### 2. 文件包含
- 通过 #include 包含相应头文件
- 头文件包含宏定义和函数声明

#### 3. 库链接
- 不常用库需要编译时指定链接选项
- 例如：gcc program.c -lm（数学库）

### 16.8.2 常用头文件

- `<stdio.h>` - I/O 相关宏与函数
- `<ctype.h>` - 字符处理宏（如 isupper、tolower）
- `<string.h>` - 字符串函数（如 strlen、strcpy）
- `<stdlib.h>` - 通用工具函数
- `<math.h>` - 数学函数
- `<time.h>` - 时间和日期函数

### 16.8.3 使用库描述

#### 阅读文档要点
- 查看函数原型和所需头文件
- 了解返回值和可能的错误
- 注意不同系统的差异

#### 旧版文档示例
```c
#include <stdio.h>
fread(ptr, sizeof(ptr), nitems, stream)
FILE *stream;
```

## 16.9 预处理器在C语言中的重要性

### 16.9.1 主要作用

1. **代码重用**：通过头文件和宏避免重复编写
2. **可移植性**：条件编译使程序适应不同环境
3. **调试支持**：条件编译便于添加/移除调试代码
4. **类型无关性**：宏处理字符串，不受变量类型限制
5. **编译时计算**：预处理阶段完成常量计算和宏展开

### 16.9.2 最佳实践

#### 宏定义
- 使用大写字母命名宏
- 适当添加括号避免优先级问题
- 避免副作用参数

#### 头文件组织
- 使用 #ifndef 防止重复包含
- 集中管理常量和函数声明
- 分离接口和实现

#### 条件编译
- 用于调试和可移植性
- 避免硬编码系统特定代码
- 使用 #error 确保环境要求

## 16.10 总结

预处理器作为C语言编译过程的第一阶段，提供了强大的代码生成和组织机制：

1. **宏系统**：通过 #define 实现代码替换和参数化
2. **文件包含**：通过 #include 实现代码模块化
3. **条件编译**：通过各种 #if 指令实现灵活的配置
4. **预定义支持**：提供编译器信息和诊断工具
5. **现代特性**：C11的 _Generic 和内联函数增强了类型安全和性能

预处理器指令使C语言具备了高度的灵活性和可移植性，是系统编程和跨平台开发的重要工具。正确使用预处理器可以显著提高代码的可维护性和效率。
