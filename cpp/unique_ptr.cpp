#include <iostream>
#include <memory>

using namespace std;

class Foo {
public:
  Foo() {
    cout << "ctor()" << endl;
  }

  ~Foo() {
    cout << "dtor()" << endl;
  }
  
};

void unique_ptr_func() {
  auto ptr = unique_ptr<Foo>(new Foo());
}

void raw_ptr_func() {
  auto ptr = new Foo();
}

int main() {
  // raw_ptr_func();
  unique_ptr_func();
  return 0;
}
