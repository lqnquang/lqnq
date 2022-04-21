#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std; 

int generateRandomNumber(); 
int getPlayerGuess(); 
void printAnswer(int guess, int secretNumber); 
void playGuessIt(); 

int main() {
    string choose = "yes";    
    do {
        playGuessIt();
        cout << "Play again??" << endl
             << "  (yes/no)  " << endl;
        cin >> choose;
        if (choose == "no") {
            cout << "Get out :((" << endl;
        } else {
            if (choose == "yes") {
                cout << "............" << endl;
            }
        }
     } while (choose == "yes");
}

int generateRandomNumber() {
    srand(time(NULL));
    int randomNumber = rand() % 100 + 1;
    return randomNumber;
}

int getPlayerGuess() {
    int guess;
    cout << "Enter your guess: ";
    cin >> guess;
    return guess;
}

void printAnswer(int guess, int secretNumber) {
    if (guess > secretNumber) {
        cout << "Your number is too big!" << endl << endl;
    } else {
        if (guess < secretNumber) {
            cout << "Your number is too small!" << endl << endl;                
        } else {
            cout << "Congratulation! You win!!!" << endl << endl;
        }   
    }
}

void playGuessIt() {
    int secretNumber = generateRandomNumber();
    int guess;
    do {
        guess = getPlayerGuess();
        printAnswer(guess, secretNumber);
    } while (guess != secretNumber);
}