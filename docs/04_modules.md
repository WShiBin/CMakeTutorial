# Modules模块

文档:https://cmake.org/cmake/help/latest/manual/cmake-modules.7.html

>  在其它编程语言中,比如说java,拓展CMake的功能

## 内置Modules:

* CMake内置的module
* 自己定制的module

## 相关命令:

```bash
# 显示可用的module模块列表
$ cmake --help-module-list

# 显示指定模块的帮助信息
$ cmake --help-module CMakePrintHelpers
```



## 常用内置模块

* CMakePrintHelpers: 方便打印参数
* GNUInstallDirs:方便配置安装目录
* check:检查模块
  * CheckIncludeFile: 检查头文件是否存在
  * CheckSymbolExists: 检查Symbol是否存在
  * CheckCCompilerFlag: 检查C编译器Flag
* FetchContent: 下载内容模块(下载源代码,文件)
* CMakePackageConfigHelpers: 包配置文件帮助模块
* Find Modules:用来找依赖库,下节讲
* CPack: 打包模块,后面讲
* CTest: 测试模块
* GoogleTest: Google测试模块

### CMakePrintHelpers模块

**提供了两个function/command**

* cmake_print_properties: 方便打印属性
* cmake_print_variables: 方便打印变量

**模块的使用步骤:**

1. 使用`include()`命令引入模块
2. 使用模块中提供的function/command

CMakeLists.txt文件:

```cmake
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(01CMakePrintHelpers)

set(CMAKE_BUILD_TYPE Debug)

message(STATUS "WARNING:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})

# 1.引入模块
include(CMakePrintHelpers)

# 2.使用模块中提供的function/command
cmake_print_variables(CMAKE_BUILD_TYPE)

add_executable(CMakePrintHelpers main.c)
```

### GNUInstallDirs

### CheckIncludeFile

检查头文件是否存在

* `CHECK_INCLUDE_FILE(<include> <variable> [<flags>])`

CMakeLists.txt文件:

```cmake
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(03CheckIncludeFile)

# 1.引入模块
include(CheckIncludeFile)
CHECK_INCLUDE_FILE(stdio.h HAVE_STDIO_H)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/header.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/header.h
)

add_executable(CheckIncludeFile main.c)
```

header.h.in文件:

```cmake
#cmakedefine HAVE_STDIO_H ${HAVE_STDIO_H}
```

main.c文件:

```c
#include <stdlib.h>
#include <string.h>
#include "header.h"

#if HAVE_STDIO_H
#include <stdio.h>
#endif

int main(int argc, char* argv[]) {
#if HAVE_STDIO_H
    printf("have stdio.h\n");
#endif
    return 0;
}
```

### CheckSymbolExists

检查Symbol是否存在

Symbol: 符号/标记 (function, variable, macro) 

* `check_symbol_exists(<symbol> <files> <variable>)`

CMakeLists.txt文件:

```cmake
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(04CheckSymbolExists)

# 1.引入模块
include(CheckSymbolExists)

# Check for macro SEEK_SET
check_symbol_exists(SEEK_SET "stdio.h" HAVE_SEEK_SET)
# Check for function fopen
check_symbol_exists(fopen "stdio.h" HAVE_FOPEN)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/header.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/header.h
)

add_executable(CheckSymbolExists main.c)
```

header.h.in文件:

```cmake
#cmakedefine HAVE_SEEK_SET ${HAVE_SEEK_SET}
#cmakedefine HAVE_FOPEN ${HAVE_FOPEN}
```

main.c文件:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(int argc, char* argv[]) {
#if HAVE_FOPEN
    FILE* file = fopen("CMakeLists.txt", "r");
#if HAVE_SEEK_SET
    fseek(file, 0, SEEK_SET);
#endif
#endif

    return 0;
}
```


### FetchContent

### CMakePackageConfigHelpers





Modules are `<script>.cmake` files located in the `CMAKE_MODULE_PATH`.

Modules can be loaded with the `include()` command.

## 其它相关:

变量: `CMAKE_MODULE_PATH`

通过`include()`和`find_package()`会去`CMAKE_MODULE_PATH`下找模块



**CMakeDependentOption**

> 设置一个option依赖于另一个option

```cmake
include(CMakeDependentOption)

cmake_dependent_option(
    option_var "docs"
        ON "condition_expreesion" OFF
)
```

如果condition_expreesion是true, option_var是ON, 反之option_var是OFF

