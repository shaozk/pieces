#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Element {
public:
  int elem;
  struct ElementCmp {
    bool operator()(const Element& a, const Element& b) {
      return a.elem < b.elem;
    }
  };
};

int main() {
  auto vecs = vector<Element>{Element{1}, Element{2}, Element{3}};

  cout << "minmax_element():" << endl;
  auto pair = minmax_element(vecs.begin(), vecs.end(), Element::ElementCmp());
  cout << pair.first->elem << " " << pair.second->elem << endl;

    cout << "max_element():" << endl;
  auto max = max_element(vecs.begin(), vecs.end(), Element::ElementCmp());
  cout << max->elem << endl;

  cout << "min_element():" << endl;
  auto min = min_element(vecs.begin(), vecs.end(), Element::ElementCmp());
  cout << min->elem << endl;
}
