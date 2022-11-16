# 模板
模板的哲学在于将一切可以在编译期完成的问题都放在编译期完成，
从而大幅度提升运行时的性能

## 外部模板
传统 c++ 中模板在编译器发现完整定义的模板就会实例化，
从而产生了重复的实例化操作，也增加了编译时间

c++11 中引入了外部模板，扩充了原来的强制编译器在特定位置实例化的语法
显式通知编译器合适进行模板的实例化

```c++
template class std::vector<boot>;         //强行实例化
extern template class std::vector<double>;//不再该编译文件中实例化模板
```

## “>”括号
传统c++ 中 **>>** 会被理解为右移
如果遇到嵌套的stl代码 
```c++
std::vector<std::vector<int>>   matrix;
//这种情况在c++11 之前的版本则会理解为右移
//在之前的写法只能使用  vector<vector<int> > 
```

## 类型别名模板

模板是用来产生类型的
传统c++中，**typedef** 可以为类型定义一个新名称，但是无法为模板定义一个新名称
因为，模板不是类型
```c++
template<typename T, typename U>
class MagicType{
  public:
    T dark;
    U magic;
};

//不合法
template<typename T>
typedef MagicType<std::vector<T>,std::string> FakeDarkMagic;
```

c++11 使用 **using** 引入了如下形式的写法，并同时支持传统 **typedef**相同的功效

> 通常使用 typedef 原名称 新名称；
> 但是函数指针等别名的定义语法却不相同，会造成阅读困难

## 变长参数模板
c++11 的标准中允许无论是类模板还是函数模板支持任意个数任意类别的模板参数，
同时不需要在定义时将参数的个数固定

```c++
template<typename... Ts> class Magic;
```
模板类Magic的对象
```c++
class Magic<int,
            std::vector<int>,
            std::map<std::string,
            std::vector<int>>> darkMagic;
//模板的参数个数允许为0
//如果不希望模板参数为0个，可以手动至少定义一个模板参数
template<typename Require,typrname ... Args> class Magic;

```
