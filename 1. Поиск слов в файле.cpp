#include <iostream>
#include <vector>
#include <fstream>

void wordsFound(std::string word, std::vector<std::string>& buffer) {
    std::fstream words;
    words.open("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\1. Поиск слов в файле\\words.txt");
    
    int wordCount = 0;
    std::string currentWord;
    while (!words.eof()) {
        while (words >> currentWord) {
            if (word == currentWord) {
                wordCount++;
            }
        }
    }
 
    std::cout << word << " found " << wordCount << " times."
        << std::endl;
 
    words.close();
}

int main()
{
    std::vector<std::string> buffer; //для хранения слов из файла
    std::string word;
    std::cout << "Enter searched word\n";
    std::cin >> word;
    wordsFound(word, buffer);

}