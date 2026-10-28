#include <iostream>


template <typename T>
class Any {
public:
  Any(T t) : data(t) {}
  T get() { return data; }
  void set(T t) { data = t; }
private:
  T data;
};


int main() {
  Any<int> a(10);  
  std::cout << a.get() << std::endl;

  Any<float> b(1.0);
  std::cout << b.get() << std::endl;
}
