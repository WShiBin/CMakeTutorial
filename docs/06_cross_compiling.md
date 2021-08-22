# 工具链和交叉编译

移动或嵌入式开发

CMAKE_STAGING_PREFIX



## 工具链文件

`CMAKE_TOOLCHAIN_FILE` 变量

```cmake
cmake -DCMAKE_TOOLCHAIN_FILE=myToolchain.cmake path/to/source
```

工具链文件必须在第一次运行CMake的构建目录时指定， 不能在之后添加或更改指向不同的工具链。因为变量本身是缓存的

工具链文件内容：

* 描述目标系统的基本信息。 
* 提供工具的路径(通常是编译器的路径)。 
* 设置工具的默认标志(通常只针对编译器，也可能是链接器)。 
* 交叉编译的情况下设置目标平台文件系统根目录的位置。

### 定义目标系统

* `CMAKE_SYSTEM_NAME`：描述目标平台的类型；（CMAKE_CROSSCOMPILING会被隐式的设置成true）
* `CMAKE_SYSTEM_PROCESSOR`：描述目标平台的硬件架构
* `CMAKE_SYSTEM_VERSION`：描述目标平台的SDK版本；根据不同平台来指定
  * Android：21（API level）
  * WindowsPhone：8.1（SDK Version）
  * Other：设置为1，或者不设置

### 指定工具路径（编译器）

```cmake
set(CMAKE_C_COMPILER gcc) 
set(CMAKE_CXX_COMPILER g++)
set(extraOpts "-Wall -Wextra") 
set(CMAKE_C_FLAGS_DEBUG_INIT ${extraOpts}) 
set(CMAKE_CXX_FLAGS_DEBUG_INIT ${extraOpts})
```

### 系统根目录