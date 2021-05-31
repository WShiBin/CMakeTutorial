# Hello world

> Hello world 仪式

## 步骤

1. 在根目录新建`CMakeLists.txt`文件
2. 在`CMakeLists.txt`文件中添加脚本
3. 写C源代码`main.c`

`CMakeLists.txt`文件:

```cmake
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(00helloworld)

add_executable(helloworld main.c)
```

`main.c`文件:

```c
#include <stdio.h>

int main(int argc, char* argv[]) {
    puts("hello cmake\n");
    return 0;
}
```

编译命令:

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./helloworld
hello cmake

```



## 解释

### `CMakeLists.txt`文件:

### 编译命令:

## 流程

> CMake是一个**构建生成器**(build system **generator**), 不是build system

CMake不能编译项目,先生成local build system,比如make(Makefile)



## CMake命令



## 其它概念

### 变量

### 构建方式

* 外部构架 out-of-source build👍
* 内部构建 in-source build

