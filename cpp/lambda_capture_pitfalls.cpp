
#include <functional>

using namespace std;

function<int()> create_func() {
  int local = 1;
  return [&local]() { return local; };   // 按引用捕获局部变量（陷阱）
}

int main() {
  auto f = create_func();
  int val = f();
  return 0;
}
