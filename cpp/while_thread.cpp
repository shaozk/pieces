#include <thread>
#include <iostream>

std::atomic<bool> stop(false);

void loop() {
  std::cout << "thread:start" << std::endl;
  while (!stop) {
    std::cout << "thread:hello" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  std::cout << "thread:end" << std::endl;
}

int main() {
  std::cout << "main:start" << std::endl;
  std::thread t(loop);
  std::this_thread::sleep_for(std::chrono::seconds(5));
  stop.store(true);
  while (t.joinable()) {
    t.join();
  }
  std::cout << "main:end" << std::endl;
  return 0;
}
