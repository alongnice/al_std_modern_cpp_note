
#include <iostream>
#define LEN 10

//返回变量值2
int len_foo(){
  int i = 2;
  return i;
}
//返回常量表达式5
constexpr int len_foo_constexpr(){
  return 5;
}

constexpr int fibonacci(const int n){
  return n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
}

int main(){
#if 1
  char arr_1[10];//合法,直接常量
  char arr_2[LEN];//合法，常量宏
  
  int len = 10;
  //char arr_3[len];//非法，变量

  const int len_2 = len+1;//变量计算出来常量
  constexpr int len_2_constexpr = 1 + 2 + 3;//常量计算出来的常量
  //char arr_4[len_2];//非法
  char arr_4[len_2_constexpr];//合法

  //char arr_5[len_foo()+5];//非法
  char arr_6[len_foo_constexpr()+1];//合法

  std::cout << fibonacci(10) << std::endl;
  // 1,1,2,3,4,8,13,21,34,55  裴伯纳且数列
  std::cout << fibonacci(10) << std::endl;
  std::cout << "old" << std::endl;
#endif
  std::cout << "new" << std::endl;
  int p = 100;
  int q[p];
  
  return 0;
  
}
