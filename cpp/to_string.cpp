#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
  int a = 23;
  string s = to_string(a);
  cout << s << "s type is: " << typeid(s).name() << endl;
  return 0;
}
