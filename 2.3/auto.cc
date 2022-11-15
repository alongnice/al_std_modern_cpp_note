#include <initializer_list>
#include <iostream>
#include <vector>

using namespace std;

class MagicFoo {
public:
  std::vector<int> vec;
  MagicFoo(std::initializer_list<int> list) {
    for (auto it = list.begin(); it != list.end(); ++it)
      vec.push_back(*it);
  }
};

//函数目前不支持
// int add(auto x, auto y) { return x + y; }

int main() {
  MagicFoo magicfoo = {1, 2, 3, 4, 5};
  cout << "magicfoo: ";
  for (auto it = magicfoo.vec.begin(); it != magicfoo.vec.end(); ++it)
    cout << *it << '\t';
  cout << endl;

  auto i = 5;
  auto arr = new auto(10);
//   cout << add(i, arr) << endl;

  return 0;
}