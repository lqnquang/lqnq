#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

const int max_bad_guess = 7;
const char DATA_FILE[] = "Ogden_Picturable_200.txt";
const string figure[] = {
    " -------------     \n"
    " |                 \n"
    " |                 \n"
    " |                 \n"
    " |                 \n"
    " |     \n"
    " ----- \n",
    " -------------     \n"
    " |           |     \n"
    " |                 \n"
    " |                 \n"
    " |                 \n"
    " |     \n"
    " ----- \n",
    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |                 \n"
    " |                 \n"
    " |     \n"
    " ----- \n",
    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |           |     \n"
    " |                 \n"
    " |     \n"
    " ----- \n",
    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |          /|     \n"
    " |                 \n"
    " |     \n"
    " ----- \n",
    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |          /|\\   \n"
    " |                 \n"
    " |     \n"
    " ----- \n",
    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |          /|\\   \n"
    " |          /      \n"
    " |     \n"
    " ----- \n",
    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |          /|\\   \n"
    " |          / \\   \n"
    " |     \n"
    " ----- \n",
};

string chooseWord(const char* filename);
char readAGuess();
void renderGame(const string& guessedWord, const int& badGuessCount, const string& wrongWord);
void update(string& guessedWord, const string& secretWord, const char& guess);
bool contains(const string& secretWord, const char& guess);
string toLowerCase(const string& s);

int main() {
    srand(time(NULL));
    string secretWord = chooseWord(DATA_FILE);
    if (secretWord.length() < 1) {
        cout << "Error reading vocabulary file " << DATA_FILE;
        return -1;
    }
    string guessedWord = string(secretWord.length(), '-');
    string wrongWord;
    int badGuessCount = 0;
    do {
        renderGame(guessedWord, badGuessCount, wrongWord);
        char guess = readAGuess();
        if (contains(secretWord, guess)) 
            update(guessedWord, secretWord, guess);
        else {
            badGuessCount++;
            wrongWord += guess;
        }
    } while (badGuessCount < max_bad_guess && secretWord != guessedWord);
    renderGame(guessedWord, badGuessCount, wrongWord);
    if (badGuessCount < max_bad_guess)
        cout << "Congratulations! You win!";
    else cout << "You lost. The correct word is " << secretWord;
}

string chooseWord(const char* filename) { //chọn từ bí mật
    vector<string> wordList;
    ifstream file(filename);
    if (file.is_open()) {
        string word;
        while (file >> word) {
            wordList.push_back(word);
        }
        file.close();
    }
    if (wordList.size() > 0) {
        int randomIndex = rand() % wordList.size();
        return toLowerCase(wordList[randomIndex]);
    } else 
        return " ";
}

char readAGuess() { //người chơi đoán 1 chữ
    char guess;
    cout << "Enter your guess: ";
    cin >> guess;
    if ('A' <= guess && guess <= 'Z')
        guess += 32;
    return guess;
}

void renderGame(const string& guessedWord, const int& badGuessCount, const string& wrongWord) {    //hình ảnh trò chơi
    system("cls");  //xoa man hinh
    cout << figure[badGuessCount] << endl << endl;
    cout << guessedWord << endl;
    cout << "Number of wrong guesses: " << badGuessCount << "-" << wrongWord << endl;
}

void update(string& guessedWord, const string& secretWord, const char& guess) {  //hiện chữ đã đoán đúng
    for (int i = secretWord.length() - 1; i >= 0; i--) {
        if (secretWord[i] == guess) {
            guessedWord[i] = guess;
        }
    }
}

bool contains(const string& secretWord, const char& guess) {  //kiểm tra người chơi đoán đúng hay sai
    for (int i = 0; i < secretWord.length(); i++) {
        if (guess == secretWord[i]) {
            return true;
        }
    }
    return false;
}

string toLowerCase(const string& s) {
    string res = s;
    transform(s.begin(), s.end(), res.begin(), ::tolower);
    return res;
}


