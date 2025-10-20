#include "libft.h"

calloc 用来分配内存并自动初始化为零。

和 malloc 不同，malloc 只分配空间但内容是垃圾值，而 calloc 会额外地把所有字节设为0。

实际上就是 malloc(count * size) 再加上 memset(..., 0, count * size) 的组合。

