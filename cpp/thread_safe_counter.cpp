#include <iostream>
#include <thread>
#include <mutex>

class Counter {
public:
  Counter() :value_(0) {}

  int get() {
    std::lock_guard<std::mutex> lock(mutex_);
    return value_;
  }
  int getAndIncrease() {
    std::lock_guard<std::mutex> lock(mutex_);
    return value_++;
  }
  
private:
  int value_;  // std::atomic 更合理
  mutable std::mutex mutex_;
};


const int kNum = 10000;

void increaseCounter(Counter& counter) {
  for (int i = 0; i < kNum; ++i) {
    counter.getAndIncrease();
  }
}

int main() {
  Counter counter;
  std::thread t1(increaseCounter, std::ref(counter));
  std::thread t2(increaseCounter, std::ref(counter));
  t1.join();
  t2.join();
  std::cout << counter.get() << std::endl;
  return 0;
}
