#include <iostream>

void test() {
  if (true) {
    throw std::runtime_error("runtime error");
  }
}
int main() {
  try {
    test();
  } catch (std::runtime_error err) {
    std::cerr << err.what() << std::endl;
  }
  return 0;
}
