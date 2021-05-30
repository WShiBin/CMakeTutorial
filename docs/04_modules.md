https://cmake.org/cmake/help/latest/manual/cmake-modules.7.html



>  拓展CMake的功能

## 两类:

* CMake内置的module
* 自己定制的module



## 其它相关:

变量:[`CMAKE_MODULE_PATH`](https://cmake.org/cmake/help/latest/variable/CMAKE_MODULE_PATH.html#variable:CMAKE_MODULE_PATH)

通过include来引入

cmake --help-module module_name



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

