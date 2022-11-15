2.1 章节讲述常量

# 推荐使用nullptr

## 引入问题：
传统意义 NULL会被编译器理解为 0 或者 ((void)*0)

c++不允许直接将 void * 进行隐式转换成其他的类型
如果尝试使用c语言中的语法

```c++
char *ch = NULL;

void foo(char *);
void foo(int);
```
那么调用的
foo(NULL);  会被改为  foo(int)  代码便违反了直觉

## 解决方案
为了解决上述问题提供了
nullptr 的关键字(属于对NULL功能的完善)
专门用来区分 空指针，0
nullptr 的类型也被定义为 nullptr_t 支持隐式转换为任何指针或者成员指针，进行比较

当前目录 nullptr.cc 中进行了一个 NULL 与以上这些值的比较过程
得到（环境为g++）
NULL 不同于 0或者nullptr

## 结论请区别使用 NULL 和 nullptr

## 备注
nullptr.cc 中使用的
decltype：作用是类型推导
std::is_same: 作用是类型比较是否相同
属于现代c++ 语法

# constexpr

# 引入问题
c语言与c++ 中都允许 常量的直接使用
1+2 或者 3*4 这种操作可以直接且没有副作用的植入程序

在程序 constexpr.cc 中举例了部分情况下的非法情况
主要是不希望申请数组时，使用变量，但是目前常见的编译器已经默认进行了优化
所以基本都能编译成功，但是应当避免如此使用

## 提供解决方案

c++11： 标准中 提供了 constexpr 让用户显式生命的函数或对象构造函数在编译器形成常量表达式
constexpr 修饰的函数液支持使用递归
c++14: 标准中 constexpr函数可以在内部使用局部变量，循环和分支等简单语句
在c++11 中不被允许,例如 constexpr.cc 中的分支函数实现或者三目运算符实现

```c++
//c++11中不被允许，c++14中支持
constexpr int fibonacci(const int n){
  if(n == 1) return 1;
  if(n == 2) return 1;
  return fibonacci(n-1) + fibonacci(n-2);
}
//c++11后都支持
constexpr int fibonacci(const int n){
  return n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
}

```
