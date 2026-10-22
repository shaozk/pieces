#include <iostream>

int main() {
  #ifdef __cplusplus
    std::cout << __cplusplus << std::endl;
  #endif
  return 0;
}

