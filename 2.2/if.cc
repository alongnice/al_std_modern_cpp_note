#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  std::vector<int> vec = {1,2,3,4};

  //在c++17之前
  const std::vector<int>::iterator itr = std::find(vec.begin(),vec.end(),2);
  if(itr != vec.end())
    *itr = 3;
  //代码逻辑找到第一个2 如果能找到把它提换成3
  
  //需要重新定义一个新的变量
  const std::vector<int>::iterator itr2 = std::find(vec.begin(),vec.end(),3);
  if(itr2 != vec.end())
    *itr2 = 4;
  //代码逻辑找到第一个3 如果能找到就替换程4
  
  //将输出1，4，3，4
  for(std::vector<int>::iterator element = vec.begin(); element != vec.end(); ++element)
    std::cout << *element << std::endl;
  //for循环中创建一个跌代器，进行循环便利输出
#ifdef NEW
  std::cout << "NEW"<< std::endl;
  if(const std::vector<int>::iterator itr3 = std::find(vec.begin(),vec.end(),3); itr != vec.end())
    *itr = 4;

    //将输出1，4，3，4
  for(std::vector<int>::iterator element = vec.begin(); element != vec.end(); ++element)
    std::cout << *element << std::endl;
  //for循环中创建一个跌代器，进行循环便利输出

#endif

  
  return 0;
}

//老版本代码已经支持for循环中的临时变量
