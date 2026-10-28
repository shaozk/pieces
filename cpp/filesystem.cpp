#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
  const std::string filepath = "filesystem.cpp";
  fs::path path(filepath);
  std::cout << path << std::endl;

  return 0;
}
