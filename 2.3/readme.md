# 类型推导
	c++11 引入了 auto 和 deletype 完成类型推导

## auto
	传统c++中，作为存储类型的指示符存在，与register并存。
	也就是说一个变量如果没有被声明 register 变量，则自动视为 auto
	目前 register 的功能已经取消

	auto 用途中最常见并且功能显著的例子就是跌代器
	例如之前程序中出现的
```c++
for(vector<int>::const_iterator it = vec.cbegin();
				it != vec.cend();
				++it;
)
```

	如果使用 auto 之后可以使用 auto.cc 文件中的用法

## decltype
	用来弥补auto只能对变量进行类型推导的缺点而出现的，用法于typeof相同
```c++
decltype(表达式)

auto x = 1;
auto y = 2;
decltype(x+y) z;

//在前面章节的例子中出现过对类型进行比较的操作

if(std::is_same<decltype(x),int>::value)
	std::cout<<"type x == int" << std::endl;
```
	其中  std::is_same<T,U>  用于判断类型是否相同


## 尾返回类型推导
	auto 在前文介绍时提到，auto不能用于函数类型推导，以加法为例
	传统c++
```c++
template<typename R, typename T, typename U>
R add(T x,U y){
	return x+y;
}


```
