#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void listReading(std::vector<std::string>& buffer, int& maxSalary,
	std::string& maxSalaryName, int& sumSalary) {

	std::ifstream list;
	list.open("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\3. Ведомость с выплатами\\list.txt");

    std::string line;
    while (getline(list, line)) {
        buffer.push_back(line);
    }

    list.close();

    std::string firstName, lastName, date;
    int salary;

    for (size_t i = 0; i < buffer.size(); ++i) {
        size_t pos = buffer[i].find(' ');
        firstName = buffer[i].substr(0, pos);//Извлечение имени
        buffer[i].erase(0, pos + 1);        //удаление имени из строки

        pos = buffer[i].find(' ');             
        lastName = buffer[i].substr(0, pos);//извлечение фамилии
        buffer[i].erase(0, pos + 1);           

        pos = buffer[i].find('.');
        salary = stoi(buffer[i].substr(0, pos));//строка в целое число

        date = buffer[i].substr(pos - 2, 10);//извлечение даты (ДД.ММ.ГГГГ)

        sumSalary += salary;

        if (salary > maxSalary) {
            maxSalary = salary;
            maxSalaryName = firstName + ' ' + lastName;
        }
    }
}

int main()
{
    system("chcp 1251"); // Установить кодировку
	int maxSalary;
	std::string maxSalaryName;
	int sumSalary = 0;
	std::vector<std::string> buffer; //для хранения слов из файла

    listReading(buffer, maxSalary, maxSalaryName, sumSalary);

    std::cout << "Общая сумма выплат: " << sumSalary << std::endl;
    std::cout << "Человек с максимальной суммой выплат: " 
        << maxSalaryName << " (" << maxSalary << ")" << std::endl;

}