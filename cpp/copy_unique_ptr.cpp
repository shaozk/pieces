#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<int> u = std::make_unique<int>(10);
  std::cout << *u << std::endl;
  std::cout << u << std::endl;
  auto v = std::move(u);
  std::cout << *v << std::endl;
  // std::cout << *u << std::endl;
  std::cout << u << std::endl;
  return 0;
}
