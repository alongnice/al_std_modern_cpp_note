#include <iostream>
#include <vector>
#include <initializer_list>

class MagicFoo{
public:
  std::vector<int> vec;
  MagicFoo(std::initializer_list<int> list){
    for(std::initializer_list<int>::iterator it = list.begin();
	it != list.end();
	++it
	)
      vec.push_back(*it);      
  }
};

int main(){
  //c++11标准之后
  MagicFoo magicfoo = {1,2,3,4,5};
  std::cout << "magicFoo: ";
  for(std::vector<int>::iterator it = magicfoo.vec.begin();
      it != magicfoo.vec.end();
      ++it
      )
    std::cout << *it << std::endl;

}
