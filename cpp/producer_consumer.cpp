#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> que;
constexpr int MAX_SIZE = 5;

void producer() {
  for (int i = 0; i < 10; ++i) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return que.size() < MAX_SIZE; });
    que.push(i);
    std::cout << "push: " << i << std::endl;
    cv.notify_all();
  }
}

void consumer() {
  for (int i = 0; i < 10; ++i) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return !que.empty(); } );
    int val = que.front();
    que.pop();
    std::cout << "get: " << val << std::endl;
    cv.notify_all();
  }
}

int main() {
  std::thread p(producer);
  std::thread c(consumer);
  p.join();
  c.join();
  return 0;
}
