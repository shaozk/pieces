#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{0, 8, 2, 5, 9, 7};
  std::sort(vec.begin(), vec.end());
  for (auto& item : vec) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  return 0;
}
