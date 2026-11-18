#include <thread>
#include <vector>

// 模拟一个死循环任务（高 CPU 占用）
void busy_task() {
  while (true) {
    // 无阻塞操作，持续消耗 CPU    
  }  
}

// 模拟一个低效算法任务
void slow_algorithm() {
  for (long i = 0; i < 100000000000000000L; ++i) {
    volatile int x = i * i;  // volatile 防止被编译器优化
  }
}

int main() {
  std::vector<std::thread> threads;
  threads.emplace_back(busy_task);
  threads.emplace_back(slow_algorithm);

  for (auto& t : threads) t.join();
  return 0;
}
