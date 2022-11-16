#include<iostream>
#include<vector>
#include<algorithm>

int main(){
  std::vector<int> vec = {1,2,3,4,5};
  if(auto itr = std::find(vec.begin(),vec.end(),3);itr != vec.end())
      *itr = 4;
  //遇到3转化为4

  for (auto element : vec)
    std::cout << element << std::endl;  //只读
  for (auto &element : vec)
    element+=1;                         //可写

  for(auto element : vec)
    std::cout<< element <<std::endl;
}