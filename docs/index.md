---
title: CMake
date: 2020-05-30 09:44:37
---

## CMake是什么?

官网:https://cmake.org/

> CMake is an open-source, cross-platform family of tools designed to build, test and package software. CMake is used to control the software compilation process using simple platform and **compiler independent configuration files**, and **generate native makefiles** and workspaces that can be used in the compiler environment of your choice.

开源,跨平台的**构建,测试,打包**软件工具,
使用简单平台和独立于编译器的**配置文件**来控制软件编译过程，生成可在您选择的编译器环境中使用的本机makefile和工作区



**画重点**
* 构建
* 测试
* 打包
* cmake命令及语法



**CMake设计的目标:**

> 提供一组工具，可以在不同平台上配置、构建、测试和部署项目. https://www.aosabook.org/en/cmake.html

CMake是一个**构建生成器**(build system **generator**), 不是build system，提供了强大的领域特定语言(**DSL**)来描述构建系统应该实现的功能



![img](https://static.bookstack.cn/projects/CMake-Cookbook/images/preface/1.png)

**CMake软件工具集:**

- **CMake**是描述如何在所有主要硬件和操作系统上配置、构建和安装项目，无论是构建可执行文件、库，还是两者都要构建。
- **CTest**定义测试、测试套件，并设置应该如何执行。
- **CPack**为打包需求提供了DSL。
- **CDash**将项目的测试结果在面板中展示。

CMake管理的项目的工作流发生在许多阶段(time)，我们称之为*时序*。可以简洁地总结如下图：

![img](https://static.bookstack.cn/projects/CMake-Cookbook/images/preface/2.png)

- **CMake time**或**confighure time**，是CMake运行时的情况。这个阶段中，CMake将处理项目中的CMakeLists.txt文件并配置它。
- **Generation time**配置成功后，CMake将生成本地构建工具所需的脚本，以执行项目中的后续步骤。
- **Build time**这是在平台和工具原生构建脚本上调用原生构建工具的时候，这些脚本以前是由CMake生成的。此时，将调用编译器，并在特定的构建目录中构建目标(可执行文件和库)。注意递归的CMake time箭头：这看起来令人困惑，但是我们将在本书中多次使用它，用来实现平台无关的构建。
- **CTest time**或 **test time**，运行项目的测试套件，以检查目标是否按预期执行。
- **CDash time**或**report time**，将测试结果上传到面板，与其他开发人员共享。
- **Install time**，将项目的目标、源文件、可执行文件和库从构建目录安装到安装位置。
- **CPack time**或**packaging time**，将项目打包以便发布，可以是源代码，也可以是二进制代码。
- **Package install time**，在系统范围内安装新生成的包。



## 学习步骤:

* Hello world程序 + 官方[User Interaction Guide](https://cmake.org/cmake/help/latest/guide/user-interaction/index.html#id2)
* [官方CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html) :简单走一遍CMake打包开发的流程
* [CMake语法](https://cmake.org/cmake/help/latest/manual/cmake-language.7.html)详细过一遍



### Reference:

官方Doc:https://cmake.org/cmake/help/latest/index.html
官方CMake Tutorial:https://cmake.org/cmake/help/latest/guide/tutorial/index.html

**书籍推荐:**

* CMake Cookbook英文https://www.packtpub.com/product/cmake-cookbook/9781788470711
* 中文版(Github):1.https://github.com/xiaoweiChen/CMake-Cookbook
* 中文版(书栈网):2.https://www.bookstack.cn/books/CMake-Cookbook
* 代码:https://github.com/dev-cafe/cmake-cookbook

**视频:**
* https://www.youtube.com/watch?v=bsXLMQ6WgIk&t=2413s&ab_channel=CppNow 👍
* https://www.youtube.com/watch?v=eC9-iRN2b04&t=984s&ab_channel=CppCon
* https://www.youtube.com/watch?v=y9kSr5enrSk&t=2077s&ab_channel=MeetingCpp