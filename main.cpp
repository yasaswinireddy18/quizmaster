#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("questions.txt");
    if (!file.is_open()) {
        cout << "Could not open questions.txt\n";
        return 0;
    }

    string question, opt1, opt2, opt3, opt4;
    int correct, userAnswer, score = 0, total = 0;

    while (getline(file, question)) {
        getline(file, opt1);
        getline(file, opt2);
        getline(file, opt3);
        getline(file, opt4);
        file >> correct;
        file.ignore();

        cout << "\n" << question << "\n";
        cout << "1. " << opt1 << "\n";
        cout << "2. " << opt2 << "\n";
        cout << "3. " << opt3 << "\n";
        cout << "4. " << opt4 << "\n";
        cout << "Your answer: ";
        cin >> userAnswer;

        if (userAnswer == correct) score++;
        total++;

        string blank;
        getline(file, blank);
    }

    cout << "\nQuiz finished!\n";
    cout << "Score: " << score << "/" << total << "\n";

    return 0;
}

