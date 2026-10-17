#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> que;
const int MAX_SIZE = 5;

void producer() {
  for (int i = 0; i < 10; ++i) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return que.size() < MAX_SIZE; });
    que.push(i);
    std::cout << "produce " << i << "/" << que.size() << std::endl;
    cv.notify_all();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

void consumer() {
  for (int i = 0; i < 10; ++i) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return !que.empty(); });
    int val = que.front();
    que.pop();
    std::cout << "consume " << i << "/" << que.size() << std::endl;
    cv.notify_all();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

int main() {
  std::thread p(producer);
  std::thread c(consumer);
  p.join();
  c.join();
  return 0;
}
