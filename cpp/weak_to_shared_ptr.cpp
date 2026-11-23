#include <memory>
#include <iostream>

int main() {
  std::shared_ptr<int> shared_before = std::make_shared<int>();
  std::cout << "shared before: " << shared_before.use_count() << std::endl;
  std::weak_ptr<int> weak = shared_before;
  std::cout << "weak: " << weak.use_count() << std::endl;
  std::cout << "shared before: " << shared_before.use_count() << std::endl;
  std::shared_ptr<int> shared = weak.lock();
  std::cout << "shared: " << shared.use_count() << std::endl;
  return 0;
}
