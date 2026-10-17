#include <thread>
#include <iostream>

void hello() {
  std::cout << "hello" << std::endl;
}

void world() {
  std::cout << "world" << std::endl;
}

int main() {
  std::thread t1(hello);
  std::thread t2(world);
  t2.join();
  t1.join();
  return 0;
}
