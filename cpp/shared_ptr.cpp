#include <iostream>
#include <memory>

using namespace std;

struct Node {
  shared_ptr<Node> next;
  ~Node() {
    cout << "Destroy" << endl;
  }
};

int main() {
  auto node1 = make_shared<Node>();
  auto node2 = make_shared<Node>();
  node1->next = node2;
  node2->next = node1;
  cout << node1.use_count() << endl;
  cout << node2.use_count() << endl;
  return 0;
}
