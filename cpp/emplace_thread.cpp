#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

std::mutex mtx;

int main() {
  constexpr int size = 5;
  std::vector<std::thread> threads;
  threads.reserve(size);
  for (int i = 0; i < size; ++i) {
    threads.emplace_back([i] {
      std::unique_lock<std::mutex> lock(mtx);
      std::cout << i << std::endl; });
  }
  for (int i = 0; i < size; ++i) {
    threads[i].join();
  }

  return 0;
}
