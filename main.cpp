#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

struct Question {
    string q;
    string o1, o2, o3, o4;
    int correct;
};

vector<Question> loadQuestions(string filename) {
    ifstream file(filename);
    vector<Question> questions;

    if (!file.is_open()) {
        cout << "Could not open " << filename << "\n";
        return questions;
    }

    string question, opt1, opt2, opt3, opt4, blank;
    int correct;

    while (getline(file, question)) {
        getline(file, opt1);
        getline(file, opt2);
        getline(file, opt3);
        getline(file, opt4);

        file >> correct;
        file.ignore();

        questions.push_back({question, opt1, opt2, opt3, opt4, correct});
        getline(file, blank);
    }

    return questions;
}

int main() {
    int choice;
    cout << "Choose difficulty:\n";
    cout << "1. Easy\n2. Medium\n3. Hard\n";
    cin >> choice;

    string filename;

    if (choice == 1) filename = "easy.txt";
    else if (choice == 2) filename = "medium.txt";
    else if (choice == 3) filename = "hard.txt";
    else {
        cout << "Invalid choice.\n";
        return 0;
    }

    vector<Question> questions = loadQuestions(filename);
    
    if (questions.empty()) {
        cout << "No questions available.\n";
        return 0;
    }

    srand(time(0));
    random_shuffle(questions.begin(), questions.end());

    int score = 0;
    int total = questions.size();
    int userAnswer;

    for (auto &q : questions) {
        cout << "\n" << q.q << "\n";
        cout << "1. " << q.o1 << "\n";
        cout << "2. " << q.o2 << "\n";
        cout << "3. " << q.o3 << "\n";
        cout << "4. " << q.o4 << "\n";
        cout << "Your answer: ";
        cin >> userAnswer;

        if (userAnswer == q.correct) score++;
    }

    cout << "\nQuiz finished!\n";
    cout << "Score: " << score << "/" << total << "\n";
    cout << "Percentage: " << (score * 100) / total << "%\n";

    return 0;
}

