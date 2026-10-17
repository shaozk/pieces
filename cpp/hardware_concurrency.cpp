#include <iostream>
#include <thread>

int main() {
  // 返回系统支持的最大并发数
  std::cout << std::thread::hardware_concurrency();
  return 0;
}
