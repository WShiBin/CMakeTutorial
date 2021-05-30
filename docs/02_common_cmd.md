



### 变量

* set/unset
* option

### 类型

* string
* list

### 流程控制

* if/else/elseif/endif
* foreach/endforeach
* while/endwhile
* break/continue

### 常用工具

* list
* string
* file
* math

### 自定义命令

* function/endfunction
* return
* macro/endmacro







```cmake
foreach(arg
    NoSpace
    Escaped\ Space
    This;Divides;Into;Five;Arguments
    Escaped\;Semicolon
    )
  message("${arg}")
endforeach()
```



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