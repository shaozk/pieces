#include <iostream>
#include <vector>

void print(const std::vector<int>& vec) {
  for (auto item : vec) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}


void print_ptr(const std::vector<int*>& vec) {
  for (auto item : vec) {
    std::cout << *item << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> vec1{1, 2, 3};
  std::vector<int> vec2 = vec1;
  print(vec1);
  print(vec2);

  int a = 10, b = 20;
  std::vector<int*> vec3{&a, &b};
  std::vector<int*> vec4 = vec3;
  print_ptr(vec3);
  print_ptr(vec4);
  *vec4[0] = 30;
  print_ptr(vec3);
  print_ptr(vec4);
  
  return 0;
}
