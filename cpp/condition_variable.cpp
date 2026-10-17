#include<condition_variable>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker() {
  std::unique_lock<std::mutex> lock(mtx);
  cv.wait(lock, [] { return ready; });
  std::cout << "worker: weak!" << std::endl;
}

int main() {
  std::thread t(worker);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  {
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    std::cout << "main: notify worker" << std::endl;
  }
  cv.notify_one();
  t.join();
  return  0;
}
