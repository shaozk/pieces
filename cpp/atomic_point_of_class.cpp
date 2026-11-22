#include <atomic>
#include <iostream>

class Foo {
public:
  Foo();
  ~Foo();
  
};

int main() {
  std::atomic<int> a(0);
  std::cout << a.load() << std::endl;
  a.store(1);
  std::cout << a.load() << std::endl;
  return 0;
}
