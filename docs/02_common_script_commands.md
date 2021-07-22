

# 命令Commands

文档:https://cmake.org/cmake/help/v3.20/manual/cmake-commands.7.html

CMake有自己DSL语言, 变量、函数、宏、条件、循环、注释等等

## 命令分类

* [脚本命令Scripting Commands](https://cmake.org/cmake/help/v3.20/manual/cmake-commands.7.html#scripting-commands)
  * 变量命令
  * 流程控制命令
  * 常用工具命令
  * 自定义命令
* [项目命令Project Commands](https://cmake.org/cmake/help/v3.20/manual/cmake-commands.7.html#project-commands)
* [CTest Commands](https://cmake.org/cmake/help/v3.20/manual/cmake-commands.7.html#ctest-commands)

## 变量命令

* set/unset
* option

**变量数据类型**

* BOOL类型
* STRING类型
* FILEPATH类型,文件路径
* PATH类型,目录路径
* INTERNAL类型
* LIST类型,链表集合(自己加的)

### `set`命令:

类似编程语言中的赋值等号`=`.给一个变量赋值

```cmake
# 普通变量
# 语法: set(<variable> <value>... [PARENT_SCOPE])
# * BOOL类型
# * STRING类型
# * FILEPATH类型,文件路径
# * PATH类型,目录路径
# * LIST类型,链表集合
set(bool_val1 ON) # bool bool_val1 = ON;
set(bool_val2 OFF)
set(string_val "xixi")
set(filepath_val "/Users/shibin/repo/CMakeTutorial/examples/01_common_cmd/CMakeLists.txt")
set(path_val "/Users/shibin/repo/CMakeTutorial/examples/01_common_cmd")
set(list_val1 "xixi" "hehe" "haha")
set(list_val2 "xixi;hehe;haha")

# 缓存变量
# 语法: set(<variable> <value>... CACHE <type> <docstring> [FORCE])
set(foo "bar" CACHE STRING "description for foo variable" FORCE)
message("foo: ${foo}")

# 环境变量
# 语法: set(ENV{<variable>})
# EDITOR=vim
message("ENV{EDITOR}: $ENV{EDITOR}") # vim
set(ENV{EDITOR} vi)
message("ENV{EDITOR}: $ENV{EDITOR}")
```

### `unset`命令:

```cmake
# 普通变量或缓存变量
# 语法: unset(<variable> [CACHE | PARENT_SCOPE])
unset(CMAKE_BUILD_TYPE)

# 环境变量
# 语法: unset(ENV{<variable>})
unset(ENV{EDITOR})
message(STATUS "EDITOR = $ENV{EDITOR}")
```

### `option`命令:

提供一个开关的默认选项:如果`option()`命令中的变量已经存在了,当前的`option()`命令就不执行,变量值`ON/OFF`

```cmake
set(cross_compiling_option_val ON)

# 语法: option(<variable> "<help_text>" [value])
option(cross_compiling_option_val "开启交叉编译" OFF)
message("cross_compiling_option_val: ${cross_compiling_option_val}")
```

## 流程控制

* if/else/elseif/endif
* foreach/endforeach
* while/endwhile
* break/continue

### `if/else/elseif/endif`命令

**语法**:

```cmake
if(<condition>)
  <commands>
elseif(<condition>) # optional block, can be repeated
  <commands>
else()              # optional block
  <commands>
endif()
```

**条件表达式分类**:

* 基本表达式
* 逻辑操作符
* 是否存在的检查
* 文件操作
* 比较
* 版本比较

CMake中的`True/False`:

* True: `1`, `ON`, `YES`, `TRUE`, `Y`, 非0的数字
* False: `0`, `OFF`, `NO`, `FALSE`, `N`, `IGNORE`, `NOTFOUND`, 空字符串或以`-NOTFOUND`为后缀的字符串

```cmake
# 基本表达式
## if(<constant>)
## if(<variable|string>)
set(bool_val3 ON)
if(${bool_val3})
    message("bool_val3 is ON")
endif()

# 逻辑操作符
# if(NOT <condition>)
# if(<cond1> AND <cond2>)
# if(<cond1> OR <cond2>)
# if((condition) AND (condition OR (condition)))
if(NOT ${bool_val3})
    message("NOT true: ${bool_val3}")
else()
    message("NOT false: ${bool_val3}")
endif()

# 是否存在的检查
# if(COMMAND command-name)
# if(POLICY policy-id)
# if(TARGET target-name)
# if(TEST test-name)
# if(DEFINED <name>|CACHE{<name>}|ENV{<name>})
# if(<variable|string> IN_LIST <variable>)
if(POLICY CMP0077)
    cmake_policy(SET CMP0077 NEW)
    message("set cmake_policy: cmp0077 new")
endif()

# 文件操作
# if(EXISTS path-to-file-or-directory)
# if(file1 IS_NEWER_THAN file2)
# if(IS_DIRECTORY path-to-directory)
# if(IS_SYMLINK file-name)
# if(IS_ABSOLUTE path)
# message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
if(EXISTS "${CMAKE_SOURCE_DIR}/CMakeLists.txt")
    message("${CMAKE_SOURCE_DIR}/CMakeLists.txt exists")
endif()

# 比较
# if(<variable|string> MATCHES regex)
# if(<variable|string> LESS <variable|string>)
# if(<variable|string> GREATER <variable|string>)
# if(<variable|string> EQUAL <variable|string>)
# if(<variable|string> LESS_EQUAL <variable|string>)
# if(<variable|string> GREATER_EQUAL <variable|string>)
# if(<variable|string> STRLESS <variable|string>)
# if(<variable|string> STRGREATER <variable|string>)
# if(<variable|string> STREQUAL <variable|string>)
# if(<variable|string> STRLESS_EQUAL <variable|string>)
# if(<variable|string> STRGREATER_EQUAL <variable|string>)
if(10 GREATER 8)
    message("10 GREATER 8")
endif()
if("abcde" STRGREATER "abcdf")
    message("abcde STRGREATER abcdf")
else()
    message("abcde STRLESS abcdf")
endif()

# 版本比较
# if(<variable|string> VERSION_LESS <variable|string>)
# if(<variable|string> VERSION_GREATER <variable|string>)
# if(<variable|string> VERSION_EQUAL <variable|string>)
# if(<variable|string> VERSION_LESS_EQUAL <variable|string>)
# if(<variable|string> VERSION_GREATER_EQUAL <variable|string>)
if(1.2 VERSION_GREATER 1.1.8)
    message("1.2 VERSION_GREATER 1.1.8")
endif()
```



### `foreach/endforeach`命令

**语法**:

```cmake
foreach(<loop_var> <items>)
  <commands>
endforeach()

foreach(<loop_var> RANGE <stop>)
foreach(<loop_var> RANGE <start> <stop> [<step>])
foreach(<loop_var> IN [LISTS [<lists>]] [ITEMS [<items>]])
```

**示例**:

```cmake
# 1.
# foreach(<loop_var> <items>)
#   <commands>
# endforeach()
set(list 0 1 2 3 4)
foreach(item ${list}) # 0.1.2.3.4.5.6.7.8.9
    message("item = ${item}")
endforeach()

# 2.
# foreach(<loop_var> RANGE <stop>)
foreach(item RANGE 10) # 0.1.2.3.4.5.6.7.8.9
    message("item = ${item}")
endforeach()

# 3.
# foreach(<loop_var> RANGE <start> <stop> [<step>])
foreach(item RANGE 3 10 2) # 范围3~9,上升为2: 3.5.7.9
    message("item = ${item}")
endforeach()

# 4.
# foreach(<loop_var> IN [LISTS [<lists>]] [ITEMS [<items>]])
set(A 0;1)
set(B 2 3)
set(C "4 5")
set(D 6;7 8)
set(E "")
foreach(item IN LISTS A B C D E)
    message("item = ${item}")
endforeach()
```

### `while/endwhile`命令

**语法**:

`<condition>`条件表达式参考上面`if/else/elseif/endif命令`

```cmake
# while(<condition>)
#   <commands>
# endwhile()
```

### `break/continue`命令

针对`foreach`和`while命令`,和编程语言中的`break/continue`意思一样

* `break()`:跳出循环
* `continue()`:继续下一次循环

## 常用工具

* list
* string
* file
* math

### `list`命令

```cmake
# 读
#   list(LENGTH <list> <out-var>)
#   list(GET <list> <element index> [<index> ...] <out-var>)
#   list(JOIN <list> <glue> <out-var>)
#   list(SUBLIST <list> <begin> <length> <out-var>)
set(list 1 2 3 4 5 6 7 8)
list(LENGTH list output)
message("LENGTH output = ${output}")

list(GET list 3 output) # 获取index为3的item元素
message("GET output = ${output}")

# 搜索
#   list(FIND <list> <value> <out-var>)
list(FIND list 5 output) # 返回值为5的index
message("FIND output = ${output}")

# 更新
#   list(APPEND <list> [<element>...])
#   list(FILTER <list> {INCLUDE | EXCLUDE} REGEX <regex>)
#   list(INSERT <list> <index> [<element>...])
#   list(POP_BACK <list> [<out-var>...])
#   list(POP_FRONT <list> [<out-var>...])
#   list(PREPEND <list> [<element>...])
#   list(REMOVE_ITEM <list> <value>...)
#   list(REMOVE_AT <list> <index>...)
#   list(REMOVE_DUPLICATES <list>)
#   list(TRANSFORM <list> <ACTION> [...])
list(APPEND list 100)
message("APPEND list = ${list}")
list(INSERT list 0 200)
message("INSERT list = ${list}")
list(POP_BACK list)
message("POP_BACK list = ${list}")
list(REMOVE_AT list 0)
message("REMOVE_AT list = ${list}")

# 排序
#   list(REVERSE <list>)
#   list(SORT <list> [COMPARE <compare>] [CASE <case>] [ORDER <order>])
list(REVERSE list)
message("REVERSE list = ${list}")
list(APPEND list 10)
list(SORT list COMPARE NATURAL ORDER ASCENDING)
message("SORT list = ${list}")
```

### `string`命令

```cmake
# 搜索和替换
#   string(FIND <string> <substring> <out-var> [...])
#   string(REPLACE <match-string> <replace-string> <out-var> <input>...)
#   string(REGEX MATCH <match-regex> <out-var> <input>...)
#   string(REGEX MATCHALL <match-regex> <out-var> <input>...)
#   string(REGEX REPLACE <match-regex> <replace-expr> <out-var> <input>...)
set(input "hello world")
# FINE
string(FIND ${input} "world" output)
message("FIND output = ${output}")
# REPLACE
string(REPLACE "world" "cmake" output ${input})
message("REPLACE output = ${output}")

# 操作
#   string(APPEND <string-var> [<input>...])
#   string(PREPEND <string-var> [<input>...])
#   string(CONCAT <out-var> [<input>...])
#   string(JOIN <glue> <out-var> [<input>...])
#   string(TOLOWER <string> <out-var>)
#   string(TOUPPER <string> <out-var>)
#   string(LENGTH <string> <out-var>)
#   string(SUBSTRING <string> <begin> <length> <out-var>)
#   string(STRIP <string> <out-var>)
#   string(GENEX_STRIP <string> <out-var>)
#   string(REPEAT <string> <count> <out-var>)
set(input " hello world ")
# APPEND
string(APPEND  output ${input} "xixi")
message("APPEND output:--${output}--")
# TOUPPER
string(TOUPPER ${input} output)
message("TOUPPER output:--${output}--")
# STRIP
string(STRIP ${input} output)
message("STRIP output:--${output}--")
# REPEAT
string(REPEAT ${output} 3 output)
message("REPEAT output:--${output}--")

# 比较
#   string(COMPARE <op> <string1> <string2> <out-var>)
#       <op>:LESS/GREATER/EQUAL/NOTEQUAL/LESS_EQUAL/GREATER_EQUAL
string(COMPARE EQUAL "hello" "hello" output)
message("COMPARE EQUAL output:${output}")

# 哈希
#   string(<HASH> <out-var> <input>)
#       <HASH>:MD5/SHA1/SHA224/SHA256/SHA384/SHA512/SHA3_224/SHA3_256/SHA3_384/SHA3_512
set(input "hello world")
string(MD5 output ${input})
message("MD5 output:${output}")

# Generation
#   string(ASCII <number>... <out-var>)
#   string(HEX <string> <out-var>)
#   string(CONFIGURE <string> <out-var> [...])
#   string(MAKE_C_IDENTIFIER <string> <out-var>)
#   string(RANDOM [<option>...] <out-var>)
#   string(TIMESTAMP <out-var> [<format string>] [UTC])
#   string(UUID <out-var> ...)
# ASCII
string(ASCII 97 output) # a
message("ASCII output:${output}")
# HEX
string(HEX "a" output) # 0x61
message("HEX output:${output}")
# RANDOM
string(RANDOM LENGTH 10 ALPHABET "abcdef" output)
message("RANDOM output:${output}")
# TIMESTAMP
string(TIMESTAMP output "%Y-%m-%dT%H:%M:%S" UTC)
message("TIMESTAMP output:${output}")
```

### `file`命令

```cmake
# 读
#   file(READ <filename> <out-var> [...])
#   file(STRINGS <filename> <out-var> [...])
#   file(<HASH> <filename> <out-var>)
#   file(TIMESTAMP <filename> <out-var> [...])
#   file(GET_RUNTIME_DEPENDENCIES [...])

# 写
#   file({WRITE | APPEND} <filename> <content>...)
#   file({TOUCH | TOUCH_NOCREATE} [<file>...])
#   file(GENERATE OUTPUT <output-file> [...])
#   file(CONFIGURE OUTPUT <output-file> CONTENT <content> [...])

# 文件系统
#   file({GLOB | GLOB_RECURSE} <out-var> [...] [<globbing-expr>...])
#   file(RENAME <oldname> <newname>)
#   file({REMOVE | REMOVE_RECURSE } [<files>...])
#   file(MAKE_DIRECTORY [<dir>...])
#   file({COPY | INSTALL} <file>... DESTINATION <dir> [...])
#   file(SIZE <filename> <out-var>)
#   file(READ_SYMLINK <linkname> <out-var>)
#   file(CREATE_LINK <original> <linkname> [...])
#   file(CHMOD <files>... <directories>... PERMISSIONS <permissions>... [...])
#   file(CHMOD_RECURSE <files>... <directories>... PERMISSIONS <permissions>... [...])

# Path转换
#   file(REAL_PATH <path> <out-var> [BASE_DIRECTORY <dir>])
#   file(RELATIVE_PATH <out-var> <directory> <file>)
#   file({TO_CMAKE_PATH | TO_NATIVE_PATH} <path> <out-var>)

# 传输
#   file(DOWNLOAD <url> [<file>] [...])
#   file(UPLOAD <file> <url> [...])
file(DOWNLOAD "https://www.baidu.com/index.html" index.html)

# 锁
#   file(LOCK <path> [...])
file(LOCK "cmake.lock")
file(LOCK "cmake.lock" RELEASE)

# 归档/打包
#   file(ARCHIVE_CREATE OUTPUT <archive> PATHS <paths>... [...])
#   file(ARCHIVE_EXTRACT INPUT <archive> [...])
```



### `math`命令

```cmake
# 语法: math(EXPR <variable> "<expression>" [OUTPUT_FORMAT <format>])
math(EXPR output "100 * 0xA" OUTPUT_FORMAT DECIMAL)      # output is set to "1000"
message("output = ${output}")
math(EXPR output "100 * 0xA" OUTPUT_FORMAT HEXADECIMAL)  # output is set to "0x3e8"
message("output = ${output}")
```



## 自定义命令

* function/endfunction命令
* macro/endmacro命令

之前使用的都是cmake内置的命令,命令也可以自行定义

* 能通过`function()` 或 `macro()`添加命令
* 当添加了一个新的命令替换成存在的命令,使用老的命令需要在命令前面加下划线前缀`_`.

### `function/endfunction`命令

**语法**:

```cmake
function(<name> [<arg1> ...])
  <commands>
endfunction()
```

**示例**:

```cmake
# 定义
function(my_command input output)
    # ...
    set(${output} ... PARENT_SCOPE)
endfunction()

# 使用
my_command(foo bar)
```

* `function`中变量有作用域范围,可以设置变量的`PARENT_SCOPE`来改变
* 可用的变量:input,output,ARGC,ARGV,ARGN,ARG0, ARG1, ARG2, ...
* Example:`${output}` expands to bar.

### `macro/endmacro`命令

```cmake
# 定义
macro(my_command input output)
    # ...
endmacro()

# 使用
my_command(foo bar)
```

* `macro`中的变量没有作用域,(宏在处理时会被替换)
* Text replacements:${input},${output},${ARGC},${ARGV}, ${ARGN}, ${ARG0}, ${ARG1}, ${ARG2}, ...
* Example:`${output}` is replaced by bar.

### 什么时候用function,什么时候用macro?

> Create macros to wrap commands that have output parametes.Otherwise, create a function.
> ​			-- C++Now 2017: Daniel Pfeifer “Effective CMake"

如果这个命令需要有输出参数,就使用macro,否则使用function



## CMake中的变量

**变量分类**:普通变量/缓存变量/环境变量

### **普通变量**

```cmake
# 语法: set(<variable> <value>... [PARENT_SCOPE])

set(CMAKE_BUILD_TYPE Debug) # gcc -g ...
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # gcc -fPIC ...

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

### 缓存变量

```cmake
# 语法: set(<variable> <value>... CACHE <type> <docstring> [FORCE])
set(foo "bar" CACHE STRING "none, for demo" FORCE)
```

变量会保存到构建目录的`CMakeCache.txt`文件中,

* 如果缓存中不存在同名的变量,则将这个变量写入缓存并使用
* 如果缓存中存在同名的变量,根据`FORCE`来决定是否写入缓存:
  * 如果没有带`FORCE`,这条语句不起作用,使用缓存中的变量
  * 如果有带`FORCE`,使用当前设置的值

### 环境变量

```cmake
# 语法: set(ENV{<variable>} [<value>])
set(ENV{EDITOR} vim)
message(STATUS "EDITOR = $ENV{EDITOR}")
```

## [CMake-policies](https://cmake.org/cmake/help/latest/manual/cmake-policies.7.html)策略

**问题**:

CMake软件本身也在不断更新和扩展, 以增加对新工具,平台和特性的支持,可能在老版本有些地方设计不够好,不合理的地方;cmake会在新版本中完善更新,这就会导致新的问题. 比如,同样的命令在不同的cmake版本中会有不同的行为,哪种方式来执行呢?

**作用**:

CMake 中的策略用于在多个版本之间保持向后兼容的行为. 允许项目使用“和CMake版本X.Y.Z的行为一样”

**例子:**

`option()`命令在不同的cmake版本中有不同的行为,cmake 3.13之前只支持`缓存变量`,3.13之后支持`普通变量`.这时候就需要用户来去指定使用哪种行为,通过`cmake_policy`命令

[CMP0077: option() honors normal variables.](https://cmake.org/cmake/help/latest/policy/CMP0077.html).(New in version 3.13.)

**两种行为**:

* `OLD`:即使有相同名字的普通变量存在,`option`还是会继续执行,并创建这个变量,然后在删除之前同名的普通变量
* `NEW`:当存在同名的普通变量时,此策略的行为是不执行任何操作. 普通变量不会被删除

**cmake_policy命令**:

```cmake
# 语法:
# 设置cmake policy是基于哪个版本: cmake_policy(VERSION <min>[...<max>])
# 设置cmake policy使用新的行为: cmake_policy(SET CMP<NNNN> NEW)
# 设置cmake policy使用老的行为: cmake_policy(SET CMP<NNNN> OLD)
# 获取cmake policy使用老的行为: cmake_policy(GET CMP<NNNN> <variable>)

cmake_policy(VERSION 3.12)

if(POLICY CMP0077)
    cmake_policy(SET CMP0077 NEW)
    message("set cmake_policy: cmp0077 new")
endif()
```

**`CMP<NNNN>`**

* `CMP`是CMake Policy缩写
* `<NNNN>`是CMake Policy中定义的[策略列序号](https://cmake.org/cmake/help/latest/manual/cmake-policies.7.html#policies-introduced-by-cmake-2-6),随cmake版本更新



前面讲过:

message
cmake_minimum_required

后面讲:

include
configure_file
find_package

不讲:

cmake_host_system_information
cmake_language
cmake_parse_arguments
cmake_path
cmake_policy
execute_process
find_file
find_library
find_path
find_program
get_cmake_property
get_directory_property
get_filename_component
get_property
include_guard
mark_as_advanced
separate_arguments
set_directory_properties
set_property
site_name
variable_watch

