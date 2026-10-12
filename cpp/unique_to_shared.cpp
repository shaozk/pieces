#include <iostream>
#include <memory>

void unique2shared() {
  std::unique_ptr<int> u = std::make_unique<int>(10);
  std::shared_ptr<int> s = std::move(u);    // can convert
  std::cout << *s << std::endl;
}

void shared2unique() {
  std::shared_ptr<int> s = std::make_shared<int>(10);
  std::unique_ptr<int> u = std::move(s);    // can't convert
  std::cout << *s << std::endl;
}

int main() {
  unique2shared();
  shared2unique();
  return 0;
}
