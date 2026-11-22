#include <iostream>
 
#define DISALLOW_COPY_AND_ASSIGN(classname)   \
  classname(const classname &) = delete;      \
  classname &operator=(const classname &) = delete;

#define DECLARE_SINGLETON(classname)          \
 public:                                      \
  static classname& Instance() {              \
    static classname instance;                \
    return instance;                          \
  }                                           \
                                              \
 private:                                     \
  classname();                                \
  DISALLOW_COPY_AND_ASSIGN(classname)


class Foo {
  DECLARE_SINGLETON(Foo)
};

Foo::Foo() {
  std::cout << "init foo" << std::endl;
}

int main() {
  auto& foo = Foo::Instance();
  return 0;
}
