#include <iostream>

using namespace std;

int main() {
  string str = "abcd";
  for (char ch : str) {
    ch -= 'a';
    cout << (int)ch << endl;
  }
  return 0;
}
