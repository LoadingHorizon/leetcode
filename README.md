# leetcode

This is LoadingHorizion leetcode.

## 目录结构

* 第一层为leet中的问题，命名方式：`'Problem'.replace(' ', '_').lower()`
* 第二层包括各种语言的文件夹（cplusplus, java, python）和一个md文件，md文件为问题的描述，语言的文件夹为各种语言的实现

## cplusplus

* `CMakeLists.txt`，用cmake构建工程
* `main.cpp`，主测试程序
* `problem.h`，头文件包含宏，用来选择一个Solution
* `problem_name.hpp`，name为实现的后缀，一般为实现者的名字缩写，有多种实现或者多人的实现，用后缀区分

### 编译方式

依赖cmake构建工具

```bash
mkdir build  // 在新目录中构建工程
cd build
cmake .. -Dclass=name   // name为problem_name.hpp中的name后缀
make
```

## java

* `Test.java`，主测试程序
* 每一个Solution的实现都放到一个新的包中

### 编译和运行

```bash
javac Test.java     // 编译主测试程序
cd pkg
javac Solution   // 编译Solution
cd ..
java -ea Test pkg   // -ea打开assert，pkg为要测试的Solution所在的包
```

## python

* `problem_name.py`，Solution文件
* `test.py`，主测试程序

### 运行

```bash
python test.py name // name为problem_name.py中name后缀
```

### 模板工具

<https://github.com/LoadingHorizon/lhtools>
```bash
tplmake.py -t leetcode -q "Two Sum" // c++模板
tplmake.py -t leetjava              // java模板
```

## 官网
<https://oj.leetcode.com/>
