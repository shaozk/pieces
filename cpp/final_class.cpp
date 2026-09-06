

class Base final {
};

class Derived : public Base {    // error: final class 无法被继承
};

int main() {
  return 0;
}
