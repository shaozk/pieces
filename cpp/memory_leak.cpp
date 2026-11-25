#include <thread>
#include <chrono>

int main() {
  while (true) {
    int* a = new int();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  return 0;
}
