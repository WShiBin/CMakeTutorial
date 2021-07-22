cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
cmake_policy(VERSION 3.12)

project(01_common_script_commands)

add_executable(01_common_script_commands main.c)

message("-------------------------------variable--------------------------------")
message("-------------------------------set--------------------------------")
# 普通变量
# 语法: set(<variable> <value>... [PARENT_SCOPE])
# cmake中的数据类型
# * BOOL类型
# * STRING类型
# * FILEPATH类型,文件路径
# * PATH类型,目录路径
# * LIST类型,链表集合(自己加的)
set(bool_val1 ON)
set(bool_val2 OFF)
set(string_val "xixi")
set(filepath_val "/Users/shibin/repo/CMakeTutorial/examples/01_common_cmd/CMakeLists.txt")
set(path_val "/Users/shibin/repo/CMakeTutorial/examples/01_common_cmd")
set(list_val1 "xixi" "hehe" "haha")
set(list_val2 "xixi;hehe;haha")
list(APPEND list_val1 "Usersshibin")

message("bool_val1: ${bool_val1}")
message("bool_val2: ${bool_val2}")
message("string_val: ${string_val}")
message("filepath_val: ${filepath_val}")
message("path_val: ${path_val}")
message("list_val1: ${list_val1}")
message("list_val2: ${list_val2}")

# set(CMAKE_BUILD_TYPE Debug)         # gcc -g ...
# set(CMAKE_C_STANDARD 11)            # gcc -std=c11 ...
# set(CMAKE_C_STANDARD_REQUIRED ON)
# set(CMAKE_POSITION_INDEPENDENT_CODE ON) # gcc -fPIC ...
# message("CMAKE_C_STANDARD: ${CMAKE_C_STANDARD}")

# set(CMAKE_CXX_STANDARD 14)            # g++ -std=c++14 ...
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# message("CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

# 缓存变量
# 语法: set(<variable> <value>... CACHE <type> <docstring> [FORCE])
set(foo "bar" CACHE STRING "description for foo variable" FORCE)
message("foo: ${foo}")

# 环境变量
# 语法: set(ENV{<variable>} [<value>])
# EDITOR=vim
message("ENV{EDITOR}: $ENV{EDITOR}") # vim
set(ENV{EDITOR} vi)
message("ENV{EDITOR}: $ENV{EDITOR}")

message("-------------------------------unset--------------------------------")
# 普通变量或缓存变量
# 语法: unset(<variable> [CACHE | PARENT_SCOPE])
# 环境变量
# 语法: unset(ENV{<variable>})
unset(bool_val1)
message("bool_val1: ${bool_val1}")
unset(ENV{EDITOR})
message("ENV{EDITOR}: $ENV{EDITOR}")

message("-------------------------------option--------------------------------")
# cmake_policy命令:
# cmake_policy(VERSION <min>[...<max>])
# cmake_policy(SET CMP<NNNN> NEW)
# cmake_policy(SET CMP<NNNN> OLD)
# cmake_policy(GET CMP<NNNN> <variable>)
cmake_policy(SET CMP0077 NEW)
cmake_policy(GET CMP0077 xixi)
message("xixi: ${xixi}")
set(cross_compiling_option_val ON)

# option命令:option(<variable> "<help_text>" [value])
option(cross_compiling_option_val "开启交叉编译" OFF)
message("cross_compiling_option_val: ${cross_compiling_option_val}")

message("-------------------------------if/else/elseif/endif--------------------------------")
# 基本表达式
# if(<constant>)
# if(<variable|string>)
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

message("-------------------------------foreach/endforeach--------------------------------")
# foreach(<loop_var> <items>)
#   <commands>
# endforeach()
set(list 0 1 2 3 4)
foreach(item ${list}) # 0.1.2.3.4.5.6.7.8.9
    message("item = ${item}")
endforeach()

message("----------------------------")
# foreach(<loop_var> RANGE <stop>)
foreach(item RANGE 10) # 0.1.2.3.4.5.6.7.8.9
    message("item = ${item}")
endforeach()

message("----------------------------")
# foreach(<loop_var> RANGE <start> <stop> [<step>])
foreach(item RANGE 3 10 2) # 范围3~9,上升为2: 3.5.7.9
    message("item = ${item}")
endforeach()

message("----------------------------")
# foreach(<loop_var> IN [LISTS [<lists>]] [ITEMS [<items>]])
set(A 0;1)
set(B 2 3)
set(C "4 5")
set(D 6;7 8)
set(E "")
foreach(item IN LISTS A B C D E)
    message("item = ${item}")
endforeach()

message("-------------------------------while/endwhile--------------------------------")
# while(<condition>)
#   <commands>
# endwhile()

message("-------------------------------common utils--------------------------------")
message("-------------------------------list--------------------------------")
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

message("-------------------------------string--------------------------------")
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


# JSON
#   ...

message("-------------------------------file--------------------------------")
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

message("-------------------------------math--------------------------------")
# math(EXPR <variable> "<expression>" [OUTPUT_FORMAT <format>])
math(EXPR output "100 * 0xA" OUTPUT_FORMAT DECIMAL)      # output is set to "1000"
message("output = ${output}")
math(EXPR output "100 * 0xA" OUTPUT_FORMAT HEXADECIMAL)  # output is set to "0x3e8"
message("output = ${output}")

message("-------------------------------end--------------------------------")