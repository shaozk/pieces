#include <iostream>

consteval int sqrt(int n) {
  return n * n;
}

int main() {
  constexpr int r = sqrt(10);
  int x = 10;
  int r2 = sqrt(x);  // non-const variable error
  std::cout << "r = " << r << std::endl;
  return 0;
}
