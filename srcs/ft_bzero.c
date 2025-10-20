#include "libft.h"

bzero 其实是 memset 的一个特殊版本。

它只做一件事：把内存清零。

在Unix/Linux系统中很常见。

它就是调用 memset(ptr, 0, size) 的等价物。

