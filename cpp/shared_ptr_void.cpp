#include <memory>
#include <string>

int main() {
  // invalid
  // std::shared_ptr<char> ptr_char = std::make_shared<int>();

  // valid
  std::shared_ptr<void> ptr_int = std::make_shared<int>();
  std::shared_ptr<void> ptr_char = std::make_shared<char>();
  std::shared_ptr<void> ptr_string = std::make_shared<std::string>();
  return 0;
}
