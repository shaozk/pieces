#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{0, 1, 2, 3, 4, 5};
  auto even_count = std::count_if(vec.begin(), vec.end(), [] (auto number) { return number % 2 == 0; });
  std::cout << even_count << std::endl;
  return 0;
}
