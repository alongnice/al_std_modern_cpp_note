# 2.2 变量及其初始化

## if/switch 变量声明强化

### 传统c++ 允许比较自由的声明变量，支持在循环逻辑中申请临时变量
  if.cc 中使用临时跌代器作为遍历对象 完成了整体的遍历输出过程

  在条件编译中添加了 NEW选项，进行验证

## 初始化列表

  初始化作为基本的编程语言特性，对于c++中不同对象支持 基本都支持 {} 进行初始化

  {} 一般支持 数组 无构造析构和虚函数的类或者结构体对象
  () 主要用于类对象的初始化，不建议通用

  为了解决不通用的问题 c++11 之后提供了
  std::initializer_list 允许构造函数或其他函数能像参数一样初始化列表
  打通了类对象的初始化与普通数组的桥梁

## 结构化绑定
  在c++11 之后提供了一种 类似python中元组的数据概念 std::tuple 可以用于返回多个元素
  但是c++11/c++14中没有提供简单的获取内部元素的方案
  虽然提供了 std::tie 进行拆包 但是仍然需要知道元组重的数目个数以及类型
  
  c++17中完善了这个设定
  提供了 strcut_bind.cc 文件中的实现思路
  包括变量自动类型推导  auto 

