// Code Made By _sm0
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constant variables and all that
const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

// Function prototypes
char getOption();
char getUserOption();
void showSelectedOption(char option);
void chooseWinner(char uChoice, char cChoice);

string answer; // variable for user's answer

char getOption() {
    srand(time(0));
    // Random number generator
    int num = rand() % 3 + 1;

    if (num == 1) return ROCK;
    if (num == 2) return PAPER;
    if (num == 3) return SCISSORS;
}

char getUserOption() {
    char c;
    cout << "Rock, Paper, and Scissors Game!" << endl;
    cout << "Choose one of the following options" << endl;
    cout << "(r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors " << endl;
    cin >> c;

    while (c != ROCK && c != PAPER && c != SCISSORS) {
        cout << "Please enter one of the following options only. " << endl;
        cout << "(r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors " << endl;
        cin >> c;
    }

    return c;
}

void showSelectedOption(char option) {
    if (option == ROCK) cout << "Rock" << endl;
    if (option == PAPER) cout << "Paper" << endl;
    if (option == SCISSORS) cout << "Scissors" << endl;
}

void chooseWinner(char uChoice, char cChoice) {
    if ((uChoice == ROCK && cChoice == SCISSORS) ||
        (uChoice == PAPER && cChoice == ROCK) ||
        (uChoice == SCISSORS && cChoice == PAPER)) {
        cout << "You Win!" << endl;
    }
    else if ((uChoice == ROCK && cChoice == PAPER) ||
        (uChoice == PAPER && cChoice == SCISSORS) ||
        (uChoice == SCISSORS && cChoice == ROCK)) {
        cout << "Computer Wins!" << endl;
    }
    else {
        cout << "Tie." << endl;
    }

    // Prompt to play again
    cout << "Do You Want To Play Again? (Yes/No): ";
    cin >> answer;
    if (answer == "Yes" || answer == "yes" || answer == "YES") {
        char uChoice = getUserOption();
        cout << "Your choice is: ";
        showSelectedOption(uChoice);

        cout << "Computer's choice is: ";
        char cChoice = getOption();
        showSelectedOption(cChoice);

        chooseWinner(uChoice, cChoice);
    }
    else if (answer == "No" || answer == "NO" || answer == "no") {
        cout << "Okay! you can leave!" << endl;
    }
    else {
        cout << "Invalid input. Exiting game." << endl;
    }
}

int main() {
    // User's choice
    char uChoice;
    // Computer's choice
    char cChoice;

    uChoice = getUserOption();
    cout << "Your choice is: ";
    showSelectedOption(uChoice);

    cout << "Computer's choice is: ";
    cChoice = getOption();
    showSelectedOption(cChoice);

    chooseWinner(uChoice, cChoice);

    return 0;
}
