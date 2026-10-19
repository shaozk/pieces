#include <iostream>

class Point {
public:
  constexpr Point(int x, int y) : x_(x), y_(y) {}
  constexpr sum() { return x_ + y_; }
private:
  int x_;
  int y_;
};

int main() {
  constexpr int a = 1;
  static_assert(a == 1);

  constexpr Point pt(1, 2);
  static_assert(pt.sum() == 3);
  return 0;
}
