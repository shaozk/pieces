#include <iostream>

class Shape {
public:
  enum Color { Red, Green, Blue };
  virtual void draw(Color color = Red) const {
    std::cout << "shape color: " << color << std::endl;
  }
};

class Rectangle : public Shape {
public:
  virtual void draw(Color color = Green) const {
    std::cout << "rectangle color: " << color << std::endl;
  }
};

int main() {
  Shape *shape = new Rectangle();
  shape->draw();
  return 0;
}
