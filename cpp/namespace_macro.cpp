#include <iostream>

#ifndef TMP_NAMEPSACE_START
#define TMP_NAMESPACE_START \
  namespace tmp {
#define TMP_NAMESPACE_END \
  }
#endif

TMP_NAMESPACE_START
void func() {
  std::cout << "namespace macro" << std::endl;
}
TMP_NAMESPACE_END

int main() {
  tmp::func();
  return 0;
}
