# 第14章：结构和其他数据形式 - 核心内容

## 结构体基础

### 结构声明

```c
struct book {
    char title[MAXTITLE];    // 书名
    char author[MAXAUTL];    // 作者
    float value;             // 价格
};  // 结构模版结束
```

- **关键字** `struct` + **可选标记** `book`
- 花括号内列出**成员**（可以是任意C数据类型，甚至另一个结构）
- 成员声明后必须有**分号**，表示结构定义结束

### 结构变量定义

```c
struct book library;        // 把library声明为book类型的变量
```

- `struct book` 类似 `int`、`float`，是一种**类型名**
- 编译器根据结构模板为变量分配内存

### 结构初始化

#### 传统初始化（列表初始化）

```c
struct book library = {
    "The Pious Pirate and the Devious Damsel",
    "Renee Vivotte",
    1.95
};
```

#### 指定初始化器（C99/C11）

```c
struct book surprise = { .value = 10.99 };

struct book gift = {
    .value = 25.99,
    .author = "James Broadfool",
    .title = "Rue for the Toad"
};
```

- 使用点运算符 **`.member = value`** 只对指定的成员进行初始化
- 顺序可以任意，未显式初始化的成员仍按声明顺序填充

### 访问结构成员

- **点运算符** `.` 用于结构变量直接访问成员
- 例如：`library.value`、`library.title`

```c
scanf("%f", &library.value);      // 读取价格
```

## 结构数组

### 声明

```c
#define MAXBKS 100
struct book library[MAXBKS];   // library是包含100个book结构元素的数组
```

### 访问成员

- 使用 **数组下标 + 点运算符**：`library[0].value`、`library[4].title`
- **注意**：下标写在结构名后面，不是成员名后面

```c
library[2].value   // 正确
library.value[2]   // 错误
```

## 嵌套结构

```c
struct names {
    char first[LEN];
    char last[LEN];
};

struct guy {
    struct names handle;    // 嵌套结构
    char favfood[LEN];
    char job[LEN];
    float income;
};

// 初始化嵌套结构
struct guy fellow = {
    {"Ewen", "Villard"},
    "grilled salmon",
    "personality coach",
    68112.00
};

// 访问嵌套成员（使用两次点运算符）
printf("Hello, %s!", fellow.handle.first);
```

## 指向结构的指针

### 声明和初始化

```c
struct guy *him;              // 声明指向结构的指针
him = &fellow[0];            // 让指针指向fellow[0]
```

- 结构名不是地址；必须使用 `&` 取地址

### 使用指针访问成员

- **箭头运算符** `->`：最常用的方式
  ```c
  him->income    // 访问him指向结构的income成员
  ```
- **圆点运算符**（需解引用）：
  ```c
  (*him).income  // 括号必需，因为.运算符优先级更高
  ```

### 指针与结构的关系

```c
// 如果 him == &barney，则以下三者等价：
barney.income     ==     (*him).income     ==     him->income
```

## 向函数传递结构信息

### 三种传递方式对比

| 方式 | 优点 | 缺点 | 适用场景 |
|------|------|------|----------|
| **传递成员** | 简单直观，保护原数据 | 功能受限 | 仅需要少量成员 |
| **传递指针** | 高效，通用性强 | 可能意外修改原数据 | 大型结构，追求效率 |
| **传递结构** | 代码清晰，天然保护原数据 | 复制开销大 | 小型结构 |

### 传递结构成员

```c
// funds1.c示例
double sum(double x, double y) {
    return x + y;
}

// 调用
printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefund));
```

### 传递结构指针

```c
// funds2.c示例
double sum(const struct funds *money) {
    return money->bankfund + money->savefund;
}

// 调用
printf("Stan has a total of $%.2f.\n", sum(&stan));
```

### 传递结构本身

```c
// funds3.c示例
double sum(struct funds moolah) {
    return moolah.bankfund + moolah.savefund;
}

// 调用
printf("Stan has a total of $%.2f.\n", sum(stan));
```

## 结构与malloc()

### 合理使用结构指针

```c
struct namect {
    char *fname;    // 使用指针
    char *lname;
    int letters;
};

void getinfo(struct namect *pst) {
    char temp[SLEN];
    // 分配内存并拷贝字符串
    pst->fname = malloc(strlen(temp) + 1);
    strcpy(pst->fname, temp);
    
    pst->lname = malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}

void cleanup(struct namect *pst) {
    free(pst->fname);
    free(pst->lname);
}
```

### 重要原则

1. **必须成对使用** `malloc` 和 `free`
2. **使用const指针** 保护原始数据
3. **字符数组vs字符指针**：
   - 数组：字符串存在结构内部，接口简单
   - 指针：字符串存在别处，结构只存地址，误用会导致问题

## 复合字面量（C99）

```c
// 创建临时结构值
(struct book) { "The Idiot", "Fyodor Dostoyevsky", 6.99 }
```

- 语法：`(struct 类型名) { 初始化列表 }`
- 适用于临时创建结构值（作为实参或赋值）

## 其他结构特性

### 结构赋值

```c
// C允许结构赋值（数组不行）
o_data = n_data;

// 用另一个结构初始化结构
struct names captain = right_field;
```

### 结构作为参数和返回值

```c
struct namect getinfo(void);        // 返回结构
struct namect makeinfo(struct namect info);  // 接受并返回结构
```

## 关键概念

1. **结构模板**定义了数据的组织方式
2. **结构变量**是根据模板创建的实际数据对象
3. **点运算符**用于直接访问结构成员
4. **箭头运算符**用于通过指针访问结构成员
5. **嵌套结构**允许更复杂的数据组织
6. **函数参数传递**有三种方式，各有优劣
7. **动态内存分配**为结构提供了更大的灵活性

## 最佳实践

1. **使用const**保护数据不被意外修改
2. **选择合适的传递方式**：大型结构用指针，小型结构按值传递
3. **正确管理内存**：malloc/free配对使用
4. **避免悬空指针**：指针使用后及时置NULL
5. **使用字符数组**存储字符串，避免指针误用
