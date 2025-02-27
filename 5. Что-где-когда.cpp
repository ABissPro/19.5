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

std::string getQuestionFromFile(const std::string& filePath) {
    std::string quest;
    std::ifstream question(filePath);
    if (question.is_open()) {
        while (!question.eof()) {
            question >> quest;
            std::cout << quest << " ";
        }
        question.close();
    }
    return quest;
}

void questionShow(int& currentSector) {
    
    if (currentSector == 1) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\1\\Question.txt");
    }
    else if (currentSector == 2) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\2\\Question.txt");        
    }
    else if (currentSector == 3) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\3\\Question.txt");
    }
    else if (currentSector == 4) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\4\\Question.txt");
    }
    else if (currentSector == 5) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\5\\Question.txt");
    }
    else if (currentSector == 6) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\6\\Question.txt");
    }
    else if (currentSector == 7) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\7\\Question.txt");
    }
    else if (currentSector == 8) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\8\\Question.txt");
    }
    else if (currentSector == 9) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\9\\Question.txt");
    }
    else if (currentSector == 10) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\10\\Question.txt");
    }
    else if (currentSector == 11) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\11\\Question.txt");
    }
    else if (currentSector == 12) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\12\\Question.txt");
    }
    else if (currentSector == 13) {
        getQuestionFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\13\\Question.txt");
    }
}

std::string getAnswerFromFile(const std::string& filePath, std::string& rightAnswer) {
    std::ifstream answerFile(filePath);

    if (answerFile.is_open()) {
        answerFile >> rightAnswer; //Считывание одного слова (ответа)
        answerFile.close();
    }

    return rightAnswer;
}

void getAnswer(int& currentSector, std::string& rightAnswer) {

    if (currentSector == 1) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\1\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 2) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\2\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 3) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\3\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 4) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\4\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 5) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\5\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 6) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\6\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 7) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\7\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 8) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\8\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 9) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\9\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 10) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\10\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 11) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\11\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 12) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\12\\Answer.txt", rightAnswer);
    }
    else if (currentSector == 13) {
        getAnswerFromFile("C:\\Users\\user\\Documents\\Программы\\cpp\\19.5\\5. Что-где-когда\\вопросы\\13\\Answer.txt", rightAnswer);
    }
}

int compareAnswers(const std::string& answer, const std::string& rightAnswer) {
    int audience = 0;
    int team = 0;
    if (answer == rightAnswer) {
        std::cout << "The answer is right!\n";
        team++;
    }
    else {
        std::cout << "The answer is wrong!!\n";
        audience++;
    }
    if (team > 6) {
        std::cout << "The team has won!\n";
    }
    else {
        std::cout << "The audience has won!\n";
    }
    return audience, team;
}

int main()
{
    int offset;
    std::vector<int> sectorCount(13);
    int currentSector = 1;
    std::vector<std::string> bufferQ; //хранение данных из файла вопросов
    std::string answer;
    std::string rightAnswer;
    std::vector<bool> visited(sectorCount.size(), false);

    for (int i = 0; i < sectorCount.size(); i++) {
        while (!visited[i]) {
            std::cout << "Enter an offset: ";
            std::cin >> offset;
            currentSector = sector(currentSector, offset, sectorCount, visited);

            questionShow(currentSector);

            std::cout << "Enter your answer with one word and with small letter:\n";
            std::cin >> answer;

            getAnswer(currentSector, rightAnswer);
            compareAnswers(answer, rightAnswer);
        }
    }    
}
