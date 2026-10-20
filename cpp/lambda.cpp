#include <iostream>

int main() {
  // [capture] (arguments) { body }
  auto func = []() { std::cout << "lambda" << std::endl; };
  func();
  return 0;
}
