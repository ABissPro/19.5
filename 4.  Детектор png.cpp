#include <iostream>
#include <fstream>
#include <string>

bool isPNG(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        return false;
    }

    char header[4];
    file.read(header, sizeof(header));

    // Проверяем первые 4 байта
    bool validHeader = header[0] == static_cast<char>(-119) && // -119 соответствует '\x89'
        header[1] == 'P' &&
        header[2] == 'N' &&
        header[3] == 'G';

    file.close();

    return validHeader;
}

int main()
{
    system("chcp 1251"); // Установить кодировку
    std::string filePath;
    std::cout << "Пожалуйста, введите путь к файлу: ";
    std::cin >> filePath;

    if (isPNG(filePath)) {
        std::cout << "Файл является PNG-изображением." << std::endl;
    }
    else {
        std::cout << "Файл не является PNG-изображением." << std::endl;
    }
}