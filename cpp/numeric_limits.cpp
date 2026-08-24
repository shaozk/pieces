#include <limits>
#include <iostream>

using namespace std;

int main() {
  auto int_max = std::numeric_limits<int>::max();
  auto int_min = std::numeric_limits<int>::min();
  auto int_lowest = std::numeric_limits<int>::lowest();
  std::cout << "int max: " << int_max << endl;
  std::cout << "int min: " << int_min << endl;
  std::cout << "int lowest: " << int_lowest << endl;

  return 0;
}
