#include <iostream>

using namespace std;

struct Struct {
  int x, y;
};

class Class {
public:
  int x, y;
};

int main() {
  Struct *s1 = new Struct();
  Class *c1 = new Class();
  cout << s1->x << " " << s1->y << endl;
  cout << c1->x << " " << c1->y << endl;
  Struct *s2 = new Struct;
  Class *c2 = new Class;
  cout << s2->x << " " << s2->y << endl;
  cout << c2->x << " " << c2->y << endl;
  return 0;
}
