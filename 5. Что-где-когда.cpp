#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int sector(int& currentSector, int& offset, std::vector<int>& sectorCount, std::vector<bool>& visited) {
    while (true) {
        int newSector = (currentSector + offset) % sectorCount.size();
        if (!visited[newSector]) {
            visited[newSector] = true;
            return newSector;
        }
        currentSector = (newSector + 1) % sectorCount.size();
    }
}

void getQuestion(int& currentSector) {
    std::ifstream Questions;
    Questions.open("C:\\Users\\amidamaru\\Documents\\Questions.txt");
    if (!Questions.is_open()) {
        std::cerr << "Error opening file" << std::endl;
    }
    
    std::string question;

    while (std::getline(Questions, question)) {
        std::string number;
        for (int i = 0; i < question.size(); i++) {
            if (question[i] == '.') {
                break;
            }
            number.push_back(question[i]);
        }
        int num = std::stoi(number);
        if (num == currentSector) {
            std::cout << question;
            break;
        }
    }
    Questions.close();
    
}


void getAnswer(int& currentSector, std::string& rightAnswer) {
    std::ifstream Answers;
    Answers.open("C:\\Users\\amidamaru\\Documents\\Answers.txt");
    if (!Answers.is_open()) {
        std::cerr << "Error opening file" << std::endl;
    }
    std::string answ;

    while (std::getline(Answers, answ)) {
        size_t dotPos = answ.find('.');
        if (dotPos != std::string::npos) {
            int num = std::stoi(answ.substr(0, dotPos));
            if (num == currentSector) {
                rightAnswer = answ.substr(dotPos + 2);  //Берем часть после точки + пробел
                break;
            }
        }
    }
    Answers.close();
}

void compareAnswers(const std::string& answer, const std::string& rightAnswer, int& audience, int& team) {
    if (answer == rightAnswer) {
        std::cout << "The answer is right!\n";
        team++;
    }
    else {
        std::cout << "The answer is wrong!!\n";
        audience++;
    }
}

int main()
{
    
    int offset;
    std::vector<int> sectorCount(13);
    for (int i = 0; i < sectorCount.size(); ++i) {
        sectorCount[i] = i + 1;
    }
    int currentSector = 1;
    std::string answer;
    std::string rightAnswer;
    std::vector<bool> visited(sectorCount.size(), false);

    int audience = 0;
    int team = 0;

    for (int i = 0; i < sectorCount.size(); i++) {
        std::cout << "Enter an offset: ";
        std::cin >> offset;
        currentSector = sector(currentSector, offset, sectorCount, visited);

        getQuestion(currentSector);

        std::cout << "\nEnter your answer with one word and with big letter:\n";
        std::cin >> answer;

        getAnswer(currentSector, rightAnswer);
        compareAnswers(answer, rightAnswer, audience, team);

        std::cout << "Right answer: " << rightAnswer << std::endl;
        std::cout << "Your answer: " << answer << std::endl;

        if (team == 6) {
            std::cout << "The team has won!\n";
            break;
        }
        else if (audience == 6) {
            std::cout << "The audience has won!\n";
            break;
        }     
    }
}
