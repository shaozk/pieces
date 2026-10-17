#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <chrono>
#include <vector>
#include <thread>
#include <iostream>

class ThreadPool {
public:
  ThreadPool(unsigned int size = 8) : stop(false) {
    for (int i = 0; i < size; ++i) {
       workers.emplace_back(
        [this, i] {
          while (true) {
            std::cout << "init thread: " << i << std::endl;
            std::function<void()> task;
            {
              std::unique_lock<std::mutex> lock(this->mutex);
              this->condition.wait(lock, [this] {
                                   return this->stop || !this->tasks.empty();
                                 });
              if (this->stop && this->tasks.empty()) {
                return;
              }
              task = std::move(this->tasks.front());
              this->tasks.pop();
            }
            task();
          }
        }
      );
    }
  }

  void enqueue(std::function<void()> task) {
    {
      std::unique_lock<std::mutex> lock(mutex);
      if (stop) {
        throw std::runtime_error("stoped!");
      }
      tasks.emplace(std::move(task));
    }
    condition.notify_all();
  }

  ThreadPool(const ThreadPool&) = delete;
  ThreadPool& operator=(const ThreadPool&) = delete;

  ~ThreadPool() {
    {
      std::unique_lock<std::mutex> lock(mutex);
      stop = true;
    }    
    condition.notify_all();
    for (std::thread& worker : workers) {
      worker.join();
    }
  }

private:
  std::vector<std::thread> workers;
  std::queue<std::function<void()>> tasks;

  std::mutex mutex;
  std::condition_variable condition;
  bool stop;
};

#endif // THREAD_POOL_H


void print() {
  int value = 10;
  std::cout << "hello " << value << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main() {
  ThreadPool pool;
  pool.enqueue(print);
  pool.enqueue(print);

  return 0;
}
