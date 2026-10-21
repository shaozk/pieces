#include <string>
#include <vector>

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

int main() {
  // print string
  fmt::print("Hello, world!\n");
  fmt::println("Hello, world!");

  // print container
  std::vector<int> v{1, 2, 3};
  fmt::print("{}\n", v);

  // format a string
  std::string s = fmt::format("The answer is {}.", 42);

}
