---
AIGC:
    ContentProducer: Minimax Agent AI
    ContentPropagator: Minimax Agent AI
    Label: AIGC
    ProduceID: "00000000000000000000000000000000"
    PropagateID: "00000000000000000000000000000000"
    ReservedCode1: 3046022100e45e2b19e3e2ca80d5c3f1f6dccbd636920e23be4ba91ecedce99d5ad6c665dc022100a09664be92286f9b52ee15bf73305ed8eb05174c8b9e1c68b684e85bab33d37a
    ReservedCode2: 304402200b0cd1cf465943b06de3bd9b031ddd8fdecbf3f7374bee2e1f2ec2b722df28ea022009e737adcb617a59e3c51a83b2144bd1c3b5e9ed32ee64e9600541c964288b74
---

# 第13章：文件输入/输出 - 核心内容

## 文件与文件通信基础

- **文件**：通常是在磁盘或固态硬盘上的一段已命名的存储区
- **文件处理模式**：
  - 文本模式：程序所见内容与文件实际内容不同（如换行符转换）
  - 二进制模式：程序可以访问文件的每个字节

## 文件的打开与关闭

### fopen()函数

| 细节 | 说明 |
|------|------|
| **原型** | `FILE *fopen(const char *filename, const char *mode);` |
| **作用** | 打开指定文件，返回文件指针 |
| **常见模式** | - `"r"`：只读模式<br>- `"w"`：只写模式（文件已存在则截断）<br>- `"a"`：追加模式<br>- `"r+"`：读写模式<br>- `"w+"`：读写模式（文件已存在则截断）<br>- `"a+"`：读写模式（追加） |
| **二进制模式** | 在模式后加`b`（如`"rb"`、`"wb"`） |
| **返回值** | 成功→文件指针；失败→NULL |
| **示例** | ```c<br>FILE *fp = fopen("data.txt", "r");<br>``` |

### fclose()函数

| 细节 | 说明 |
|------|------|
| **原型** | `int fclose(FILE *stream);` |
| **作用** | 关闭指定的文件，刷新缓冲区 |
| **返回值** | 成功→0；失败→EOF |
| **示例** | ```c<br>fclose(fp);<br>``` |

## 文件的读写函数

### 字符读写函数

| 函数 | 作用 | 原型 | 示例 |
|------|------|------|------|
| **getc()** | 从文件读取字符 | `int getc(FILE *stream);` | `ch = getc(fp);` |
| **putc()** | 向文件写入字符 | `int putc(int c, FILE *stream);` | `putc(ch, fp);` |

### 文本I/O函数

| 函数 | 作用 | 原型 | 示例 |
|------|------|------|------|
| **fprintf()** | 格式化写入文件 | `int fprintf(FILE *stream, const char *format, ...);` | `fprintf(fp, "Hello, %s", name);` |
| **fscanf()** | 格式化从文件读取 | `int fscanf(FILE *stream, const char *format, ...);` | `fscanf(fp, "%d %f", &i, &f);` |
| **fgets()** | 读取字符串（保留换行符） | `char *fgets(char *s, int n, FILE *stream);` | `fgets(buf, MAX_LEN, fp);` |
| **fputs()** | 写入字符串（不添加换行符） | `int fputs(const char *s, FILE *stream);` | `fputs(buf, fp);` |

### 随机访问

| 函数 | 作用 | 原型 | 关键参数 |
|------|------|------|---------|
| **fseek()** | 设置文件位置指示器 | `int fseek(FILE *stream, long offset, int whence);` | - SEEK_SET：文件开始处<br>- SEEK_CUR：当前位置<br>- SEEK_END：文件末尾 |
| **ftell()** | 获取当前文件位置 | `long ftell(FILE *stream);` | 返回距文件开始处的字节数 |

### 高级定位函数

| 函数 | 作用 | 原型 | 特点 |
|------|------|------|------|
| **fgetpos()** | 获取当前位置 | `int fgetpos(FILE *stream, fpos_t *pos);` | 使用fpos_t类型，支持大文件 |
| **fsetpos()** | 设置当前位置 | `int fsetpos(FILE *stream, const fpos_t *pos);` | 使用fpos_t类型，支持大文件 |

## 二进制I/O

### fwrite()函数

| 细节 | 说明 |
|------|------|
| **原型** | `size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);` |
| **作用** | 将数据写入文件（二进制形式） |
| **参数说明** | - `ptr`：数据块的地址<br>- `size`：每个数据项的字节数<br>- `nmemb`：数据项的数量<br>- `stream`：目标文件指针 |
| **示例** | ```c<br>double arr[10];<br>fwrite(arr, sizeof(double), 10, fp);<br>``` |

### fread()函数

| 细节 | 说明 |
|------|------|
| **原型** | `size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);` |
| **作用** | 从文件读取数据（二进制形式） |
| **参数说明** | - `ptr`：存储数据的地址<br>- `size`：每个数据项的字节数<br>- `nmemb`：数据项的数量<br>- `stream`：源文件指针 |
| **示例** | ```c<br>double arr[10];<br>fread(arr, sizeof(double), 10, fp);<br>``` |

## 状态检测函数

| 函数 | 作用 | 原型 | 返回值 |
|------|------|------|------|
| **feof()** | 检测文件结尾 | `int feof(FILE *stream);` | 到达文件结尾→非零值；否则→0 |
| **ferror()** | 检测I/O错误 | `int ferror(FILE *stream);` | 出现错误→非零值；否则→0 |

## 缓冲区管理

### fflush()函数

| 细节 | 说明 |
|------|------|
| **原型** | `int fflush(FILE *stream);` |
| **作用** | 刷新输出缓冲区，将未写入数据发送到文件 |
| **示例** | ```c<br>fflush(fp); // 刷新指定文件的缓冲区<br>fflush(NULL); // 刷新所有输出缓冲区<br>``` |

### setvbuf()函数

| 细节 | 说明 |
|------|------|
| **原型** | `int setvbuf(FILE *stream, char *buf, int mode, size_t size);` |
| **作用** | 设置自定义缓冲区 |
| **mode参数** | - `_IOFBF`：完全缓冲<br>- `_IOLBF`：行缓冲<br>- `_IONBF`：无缓冲 |
| **示例** | ```c<br>char buffer[BUFSIZE];<br>setvbuf(fp, buffer, _IOFBF, BUFSIZE);<br>``` |

## 其他实用函数

### ungetc()函数

| 细节 | 说明 |
|------|------|
| **原型** | `int ungetc(int c, FILE *stream);` |
| **作用** | 将字符放回输入流 |
| **示例** | ```c<br>ungetc(ch, fp); // 将ch放回fp指向的流中<br>``` |

## 关键概念

1. **字节流概念**：C程序把输入/输出看作是字节流
2. **函数决定解释方式**：使用的I/O函数决定了如何解释输入流或输出流
3. **文件指针**：必须创建FILE类型指针并与特定文件名关联
4. **文件结尾处理**：输入函数在读过文件结尾后才会检测到文件结尾
5. **文本vs二进制**：文本模式进行系统表示法映射；二进制模式逐字节读取

## 文件I/O最佳实践

1. **始终检查返回值**：检查`fopen()`是否返回NULL，检查`fclose()`是否成功
2. **使用二进制模式处理数值数据**：保持精度，避免格式转换开销
3. **使用缓冲区提高效率**：合理设置缓冲区大小，减少I/O操作次数
4. **正确处理文件结尾**：使用`while ((ch = getc(fp)) != EOF)`模式
5. **明确文件模式**：区分文本模式和二进制模式的使用场景
6. **及时释放资源**：使用`fclose()`关闭文件，释放缓冲区