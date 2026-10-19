
#include <iostream>

// Non-Type Template Parameter
// 非类型模版参数
template <int SIZE>
struct FixedArray {
  int array[SIZE];
  int size = SIZE;
};

int main() {
  FixedArray<10> arr1;
  std::cout << arr1.size << std::endl;
  FixedArray<4> arr2;
  std::cout << arr2.size << std::endl;
  return 0;
}
