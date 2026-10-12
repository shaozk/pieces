   
#include <iostream>

class Shape {
public:
  enum Color { Red, Green, Blue };
  void draw(Color color = Green) const {
    doDraw(color);
  }
  virtual void doDraw(Color color) const {
    std::cout << "shape color: " << color << std::endl;
  }
};

class Rectangle : public Shape {
public:
  virtual void doDraw(Color color) const override{
    std::cout << "rectangle color: " << color << std::endl;
  }
};

int main() {
  Shape *shape = new Rectangle();
  shape->draw();
  return 0;
}

