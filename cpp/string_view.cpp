#include <string>

template<typename Char>
class basic_string_view {
public:
  

private:
  const Char* data;
  size_t size;
};


using string_view = basic_string_view<char>;

int main() {
  std::string str = "hello";
  string_view sv = str;
  return 0;
}
