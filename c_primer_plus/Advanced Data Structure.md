# 第17章 高级数据表示 核心内容

## 17.1 概述

第17章重点介绍抽象数据类型（ADT）的概念和高级数据表示方法。通过学习如何设计和实现链表、队列等动态数据结构，帮助读者从编程新手成长为具备系统设计能力的程序员。

### 核心主题
- 进一步学习 malloc() 的使用
- 使用C表示不同类型的数据
- 新的算法概念
- 抽象数据类型（ADT）的概念和实现

## 17.2 从数组到链表

### 17.2.1 传统数组的局限性

#### 基本电影管理程序的问题
```c
struct film {
    char title[TSIZE];
    int rating;
};
struct film movies[FMAX];
```

**主要问题：**
1. **空间浪费**：大部分片名不超过40字符，但有些确实很长
2. **大小限制**：编译时确定数组大小，无法运行时动态调整
3. **灵活性差**：无法根据实际需要动态分配空间

### 17.2.2 链表的优势

#### 链表结构定义
```c
struct film {
    char title[TSIZE];
    int rating;
    struct film *next;  // 指向下一个结构的指针
};
```

#### 链表工作原理
1. **创建第一个节点**：
   - 使用 malloc() 分配结构空间
   - 设置 title 和 rating 成员
   - 设置 next 指针为 NULL
   - 头指针指向第一个节点

2. **添加后续节点**：
   - 为新结构分配空间
   - 将新结构地址存储在上一个结构的 next 成员中
   - 设置新结构的 next 为 NULL

3. **遍历链表**：
   ```c
   current = head;
   while (current != NULL) {
       printf("Movie: %s Rating: %d\n", 
              current->title, current->rating);
       current = current->next;
   }
   ```

4. **释放内存**：
   ```c
   current = head;
   while (current != NULL) {
       current = head;
       head = current->next;
       free(current);
   }
   ```

## 17.3 抽象数据类型（ADT）

### 17.3.1 ADT的三步抽象过程

#### 1. 抽象描述（属性 + 操作）
- 不依赖实现细节或特定语言
- 只是正式的需求描述

#### 2. 设计接口（编程语言的实现层）
- 给出结构定义和函数原型
- 相当于内部运算符

#### 3. 具体实现
- 编写函数体
- 提供实际的数据存储方式和操作实现

### 17.3.2 简单链表ADT定义

#### 抽象规格
- **类型名**：简单链表
- **属性**：能保存一系列项（元素）
- **操作**：

| 操作 | 前提条件 | 后置条件 |
|------|----------|----------|
| InitializeList | plist 指向一个链表变量 | 链表初始化为空 |
| ListIsEmpty | plist 已被初始化 | 若链表为空返回 true，否则返回 false |
| ListIsFull | plist 已被初始化 | 若链表已满返回 true，否则返回 false |
| ListItemCount | plist 已被初始化 | 返回链表中的项数 |
| AddItem | item 为待添加的项，plist 已被初始化 | 若成功在链表末尾添加项则返回 true |
| Traverse | plist 已被初始化，pfun 为接受 Item 参数的函数 | 将 pfun 作用于链表中的每一项一次 |
| EmptyTheList | plist 已被初始化 | 释放所有节点，链表重新为空 |

### 17.3.3 链表接口设计（list.h）

```c
/* list.h -- 简单链表类型的头文件 */
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>  /* C99 标准布尔类型 */

/* 电影结构（特定的 Item 类型） */
#define TSIZE 45      /* 电影标题数组大小 */
struct film {
    char title[TSIZE];
    int rating;
};

/* ---------- 通用类型定义 ---------- */
typedef struct film Item;              /* Item 为电影结构 */
typedef struct node {
    Item item;                        /* 链表节点保存的项 */
    struct node *next;                /* 指向下一个节点 */
} Node;
typedef Node *List;                   /* 链表指针类型 */

/* ---------- 函数原型 ---------- */
void InitializeList(List *plist);
bool ListIsEmpty(const List *plist);
bool ListIsFull(const List *plist);
unsigned int ListItemCount(const List *plist);
bool AddItem(Item item, List *plist);
void Traverse(const List *plist, void (*pfun)(Item item));
void EmptyTheList(List *plist);

#endif /* LIST_H */
```

### 17.3.4 ADT实现的优点

#### 1. 数据隐藏
- 用户无需关心内部实现细节
- 只需通过提供的函数操作数据
- 防止意外修改内部结构

#### 2. 接口分离
- 抽象描述与具体实现分离
- 可以修改实现而不影响使用代码
- 提供清晰的边界和责任划分

#### 3. 可重用性
- 可以用于不同类型的链表
- 只需重新定义 Item 类型
- 核心算法和接口保持不变

#### 4. 可维护性
- 问题可以定位到具体函数
- 便于调试和测试
- 支持渐进式开发

## 17.4 链表实现详解（list.c）

### 17.4.1 关键函数实现

#### InitializeList 函数
```c
void InitializeList(List *plist) {
    *plist = NULL;
}
```

#### AddItem 函数（添加项到链表末尾）
```c
bool AddItem(Item item, List *plist) {
    Node *pnew;
    Node *scan = *plist;
    
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;  /* 失败时退出函数 */
    
    CopyToNode(item, pnew);
    pnew->next = NULL;
    
    if (scan == NULL) {
        /* 空链表，所以把 pnew 放在链表的开头 */
        *plist = pnew;
    } else {
        while (scan->next != NULL)
            scan = scan->next;  /* 找到链表的末尾 */
        scan->next = pnew;     /* 把 pnew 添加到链表的末尾 */
    }
    return true;
}
```

#### Traverse 函数（遍历链表）
```c
void Traverse(const List *plist, void (*pfun)(Item item)) {
    Node *pnode = *plist;  /* 设置链表的开始 */
    
    while (pnode != NULL) {
        (*pfun)(pnode->item);  /* 把函数应用于链表中的项 */
        pnode = pnode->next;    /* 前进到下一项 */
    }
}
```

#### EmptyTheList 函数（释放链表）
```c
void EmptyTheList(List *plist) {
    Node *psave;
    
    while (*plist != NULL) {
        psave = (*plist)->next;  /* 保存下一个节点的地址 */
        free(*plist);             /* 释放当前节点 */
        *plist = psave;          /* 前进至下一个节点 */
    }
}
```

### 17.4.2 辅助函数

#### CopyToNode 函数（内部链接）
```c
static void CopyToNode(Item item, Node *pnode) {
    pnode->item = item;  /* 拷贝结构 */
}
```

使用 `static` 关键字创建内部链接函数，隐藏实现细节。

### 17.4.3 使用ADT的电影程序（films3.c）

```c
int main(void) {
    List movies;
    Item temp;
    
    InitializeList(&movies);
    
    if (ListIsFull(&movies)) {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }
    
    /* 获取用户输入并储存 */
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
        puts("Enter your rating:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;
        
        if (AddItem(temp, &movies) == false) {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        
        puts("Enter next movie title (empty line to stop):");
    }
    
    /* 显示 */
    if (ListIsEmpty(&movies))
        printf("No data entered.\n");
    else {
        printf("Here is the movie list:\n");
        Traverse(&movies, showmovies);
    }
    
    printf("You entered %d movies.\n", ListItemCount(&movies));
    
    /* 清理 */
    EmptyTheList(&movies);
    printf("Bye!\n");
    return 0;
}
```

## 17.5 队列（Queue）ADT

### 17.5.1 队列的基本概念

#### 队列定义
- **队列**是具有两个特殊属性的链表
- **先进先出**（First In, First Out，FIFO）数据结构
- 新项只能添加到链表末尾
- 只能从链表开头移除项

#### 队列的应用场景
- 任务调度系统
- 打印队列
- 缓冲区管理
- 广度优先搜索（BFS）

### 17.5.2 队列ADT定义

#### 抽象规格
- **类型名**：队列
- **属性**：可以储存一系列项
- **操作**：
  - 初始化队列为空
  - 确定队列是否为空
  - 确定队列是否已满
  - 确定队列中的项数
  - 在队列末尾添加项
  - 从队列开头移除项

#### 队列vs链表的区别
| 特性 | 简单链表 | 队列 |
|------|----------|------|
| 添加项 | 可以在末尾添加 | 只能在末尾添加 |
| 移除项 | 可以移除任意项 | 只能从开头移除 |
| 访问方式 | 支持遍历所有项 | 只支持先进先出访问 |
| 应用场景 | 一般数据存储 | 任务调度、缓冲管理 |

## 17.6 进一步的数据结构

### 17.6.1 栈（Stack）
- **后进先出**（Last In, First Out，LIFO）数据结构
- 主要操作：push（压入）、pop（弹出）
- 应用：函数调用栈、表达式求值、深度优先搜索

### 17.6.2 树（Tree）
- **层次化**数据结构
- 二叉树、平衡树、搜索树
- 应用：文件系统、数据库索引、决策树

### 17.6.3 图（Graph）
- **网络化**数据结构
- 顶点（vertex）和边（edge）
- 应用：社交网络、路由算法、网络拓扑

## 17.7 ADT设计原则

### 17.7.1 接口设计原则

#### 1. 最小化接口
- 只提供必要的操作
- 避免提供内部细节访问
- 保持接口简洁明了

#### 2. 一致性
- 参数传递方式保持一致
- 返回值语义保持一致
- 错误处理方式保持一致

#### 3. 安全性
- 防止无效操作
- 提供输入验证
- 保护内部数据完整性

### 17.7.2 实现设计原则

#### 1. 效率
- 选择合适的数据结构
- 优化关键操作
- 平衡时间和空间复杂度

#### 2. 健壮性
- 处理边界情况
- 提供错误恢复机制
- 防止内存泄漏

#### 3. 可扩展性
- 支持功能扩展
- 便于维护和调试
- 便于移植到不同平台

## 17.8 实际应用考虑

### 17.8.1 内存管理
- **动态分配**：使用 malloc() 和 free()
- **内存泄漏防护**：确保每个 malloc() 都有对应的 free()
- **内存碎片化**：考虑大内存块的分配策略

### 17.8.2 性能优化
- **算法复杂度**：分析时间和空间复杂度
- **缓存友好性**：考虑数据访问的局部性
- **并发安全**：多线程环境下的同步机制

### 17.8.3 错误处理
- **输入验证**：检查输入参数的有效性
- **异常情况**：处理内存不足、索引越界等情况
- **调试支持**：提供诊断信息和日志记录

## 17.9 总结

第17章通过抽象数据类型的方法，系统地介绍了高级数据表示的核心概念：

1. **从数组到链表**：展示了动态数据结构的优势
2. **ADT三步法**：抽象描述 → 接口设计 → 具体实现
3. **链表实现**：完整的接口设计和实现示例
4. **队列概念**：FIFO数据结构的抽象定义
5. **设计原则**：接口设计、实现设计、实际应用考虑

通过掌握ADT方法，程序员可以：
- 设计更加模块化和可维护的程序
- 复用通用的数据结构和算法
- 提高程序的可扩展性和可移植性
- 为学习面向对象编程奠定基础

这种方法不仅适用于C语言，也是现代软件开发中重要的设计思想。
