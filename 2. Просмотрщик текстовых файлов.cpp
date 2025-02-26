#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath;

    std::cout << "Enter the path to the text file: ";
    std::getline(std::cin, filePath);

    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}
