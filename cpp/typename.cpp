#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
class Foo {
public:
  typedef T Type;
};

template <typename T>
void func() {
  // 此处必须要有 typename，因为此时为依赖类型（即不确定类型）
  typename Foo<T>::Type a = 1;
  cout << "type: " << typeid(a).name() << endl;
}

int main() {
  func<int>();
  func<float>();
  return 0;
}
