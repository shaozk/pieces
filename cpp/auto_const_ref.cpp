#include <iostream>
#include <type_traits>


int main() {
  const int a = 10;
  const int& b = 10;
  auto c = a;
  std::cout << a << " " << b << std::endl;
  std::cout << "a: " << std::is_reference<decltype(a)>() << std::endl; // false
  std::cout << "b: " << std::is_reference<decltype(b)>() << std::endl; // true
  std::cout << "c: " << std::is_reference<decltype(c)>() << std::endl; // false
  return 0;
}
