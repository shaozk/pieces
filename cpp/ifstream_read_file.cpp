#include <fstream>
#include <iostream>

int main() {
    const std::string& file_path = "../txt/data.txt";
    std::ifstream ifs(file_path);
    if (!ifs.is_open()) {
        std::cerr << "encounter error" << std::endl;
    } else {
        std::cout << "open " << file_path << " success!" << std::endl;
    }
    std::string line;
    while (std::getline(ifs, line)) {
        std::cout << line << std::endl;
    }
    return 0;
}
