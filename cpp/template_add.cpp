#include <iostream>

template <typename T>
T add(T a, T b) {
  return a + b;
}

int main() {
  std::cout << add(1, 2) << std::endl;
  std::cout << add(1.0, 2.0) << std::endl;
  std::cout << add(1.0, 2.0) << std::endl;
  return 0;
}
