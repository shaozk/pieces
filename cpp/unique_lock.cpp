#include <thread>
#include <mutex>

int main() {
  std::mutex mutex;
  {
    std::unique_lock<std::mutex> lock(mutex);

  }
  return 0;
}
