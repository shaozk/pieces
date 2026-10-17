#include <functional>
#include <iostream>

void print_hello() {
  std::cout << "hello" << std::endl;
}

void print_value(int value) {
  std::cout << "value: " << value << std::endl;
}

int add(int a, int b) {
  return a + b;
}

int main() {
  std::function<void()> func1 = &print_hello;
  func1();

  std::function<void(int)> func2 = &print_value;
  func2(2);

  std::function<int(int, int)> func3 = add;
  std::cout << func3(1, 2) << std::endl;
  return 0;
}
