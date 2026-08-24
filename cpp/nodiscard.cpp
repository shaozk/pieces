#include <tuple>

struct [[nodiscard]] Status {
  int state;
};

[[nodiscard]] bool is_valid() {
  return true;
}

Status get_status() {
  return Status{1};
}

int main() {
  std::ignore = is_valid();
  std::ignore = get_status();
  return 0;
}
