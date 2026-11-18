#include <cstring>
#include <iostream>

int main() {
  const char* str = "/mnt/helllo";
  const char* slash = strrchr(str, '/');
  std::cout << "slash=" << slash << std::endl;

  return 0;
}
