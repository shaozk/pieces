#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << "iterator invalidation" << endl;
  vector<int> vec = {1, 2, 3, 4, 5};
  cout << "size = " << vec.size() << endl;
  cout << "capacity = " << vec.capacity() << endl;
  vector<int>::iterator iter;
  for (iter = vec.begin(); iter != vec.end(); ++iter) {
    cout << *iter << endl;
  }
  
  vec.insert(iter, 6);
  vec.insert(iter, 7);
  cout << "size = " << vec.size() << endl;
  cout << "capacity = " << vec.capacity() << endl;
  cout << *iter << endl;
  return 0;
}
