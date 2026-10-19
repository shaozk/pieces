#include <iostream>

void init(int* arr) {
  for (int i = 0; i < 10; ++i) {
    arr[i] = i;
  }
}

int main() {
  int arr[10];
  init(arr);
  // 数组读越界访问：程序不会终止，只会读取随机值
  for (int i = 0; i <= 10; ++i) {
    std::cout << arr[i] << " ";
  }
  // 数组写越界访问：程序终止
  for (int i = 0; i <= 10; ++i) {
    arr[i] = i;
  }
  return 0;
}
