#include <iostream>

using namespace std;

class Fuzz {
public:
  Fuzz(int z) : _z(z) {  }
  int value() { return _z; }
private:
  int _z;
};

int main() {
  Fuzz z(1);
  cout << z.value() << endl;
  return 0;
}
