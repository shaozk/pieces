#include <mutex>

class Foo {
public:
  int getVal() const {
    std::lock_guard<std::mutex> lock(mtx_);  // mtx_ must mutable
    return val_;
  }
private:
  mutable std::mutex mtx_;  // mutable
  int val_;
};

int main() {
  return 0;
}
