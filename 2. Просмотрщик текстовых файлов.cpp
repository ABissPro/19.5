#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath;

    std::cout << "Enter the path to the text file: ";
    std::getline(std::cin, filePath);

    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    constexpr size_t BUFFER_SIZE = 1024; //Размер буфера для временного хранения
    char buffer[BUFFER_SIZE];

    while (file.read(buffer, BUFFER_SIZE)) {
        std::cout.write(buffer, file.gcount());
    }

    //Обработка оставшейся части файла, если её размер менее BUFFER_SIZE
    if (!file.eof() && !file.fail()) {
        file.read(buffer, BUFFER_SIZE);
        std::cout.write(buffer, file.gcount());
    }

    file.close();

    return 0;
}

