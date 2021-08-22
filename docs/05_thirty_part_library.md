# CMake中引入三方库

## 引入方式

### 使用本地库构建：Ubuntu

* 通过find模块
* 通过**FindPkgConfig**导入

### 使用源码构建：交叉编译

* 已经有使用CMake构建的项目（cJSON，dbus）
* 没有使用CMake构建的项目：
  * 手动增加CMake（lvgl库）
  * 会写编译脚本：先编译库，然后调用cmake编译项目（curl）

