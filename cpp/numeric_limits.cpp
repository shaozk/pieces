#include <limits>
#include <iostream>

using namespace std;

template<typename T>
void calc_numeric_limits() {
  auto max = std::numeric_limits<T>::max();
  auto min = std::numeric_limits<T>::min();
  auto lowest = std::numeric_limits<T>::lowest();
  std::cout << "max: " << max << endl;
  std::cout << "min: " << min << endl;
  std::cout << "lowest: " << lowest << endl;
  
}

int main() {
  int8_t int8_max = std::numeric_limits<int8_t>::max();
  int8_t int8_min = std::numeric_limits<int8_t>::min();
  int8_t int8_lowest = std::numeric_limits<int8_t>::lowest();
  std::cout << "int8 max: " << (int)int8_max << endl;
  std::cout << "int8 min: " << (int)int8_min << endl;
  std::cout << "int8 lowest: " << (int)int8_lowest << endl;

  calc_numeric_limits<int16_t>();
  calc_numeric_limits<int>();
  calc_numeric_limits<int64_t>();

  return 0;
}
