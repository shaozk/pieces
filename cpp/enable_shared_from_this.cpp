#include <memory>
#include <iostream>

class Foo : public std::enable_shared_from_this<Foo> {
public:
  Foo() = default;
  static std::shared_ptr<Foo> create() {
    return std::make_shared<Foo>();
  }

  void process() {
    auto self = shared_from_this();
    std::cout << self.use_count() << std::endl;
    
  }
};

int main() {
  auto f = Foo::create();
  f->process();
  return 0;
}
