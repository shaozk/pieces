#include <memory>
#include <iostream>

int main() {
  auto shared = std::make_shared<int>();
  std::cout << shared.use_count() << std::endl;
  auto& shared_ref = shared;
  std::cout << shared_ref.use_count() << std::endl;
  const auto& shared_const_ref = shared;
  std::cout << shared_const_ref.use_count() << std::endl;
  auto shared_other = shared;
  std::cout << shared_other.use_count() << std::endl;
  return 0;
}

