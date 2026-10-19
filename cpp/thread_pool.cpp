#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <chrono>
#include <stdexcept>
#include <vector>
#include <thread>
#include <iostream>

class ThreadPool {
public:
  ThreadPool(int size = 8) : stop(false) {
    for (int i = 0; i < size; ++i) {
      workers.emplace_back(
        [this] {
          while (true) {
            std::function<void()> task;
            {
              std::unique_lock<std::mutex> lock(mtx);
              cv.wait(lock, [this] { return stop || !tasks.empty(); });
              if (stop && tasks.empty()) { return; }
              task = std::move(tasks.front());
              tasks.pop();
            }
            task();
          }
        }
      );
    }
  }
  ~ThreadPool() {
    {
      std::unique_lock<std::mutex> lock(mtx);
      stop = true;
    }
    cv.notify_all();
    for (auto& worker : workers) {
      worker.join();
    }   
  }
  void enqueue(std::function<void()> func) {
    std::unique_lock<std::mutex> lock(mtx);
    if (stop) {
      throw std::runtime_error("stop!");
    }
    tasks.emplace(std::move(func));
  }

private:
  std::vector<std::thread> workers;
  std::queue<std::function<void()>> tasks;

  std::mutex mtx;
  std::condition_variable cv;
  std::atomic<bool> stop;
};

#endif // THREAD_POOL_H


void test() {
  int value = 10;
  std::cout << "hello " << value << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main() {
  ThreadPool pool;
  pool.enqueue(test);
  pool.enqueue(test);
  return 0;
}
