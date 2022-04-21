#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
int main() {
    int i = 0;
    while (i <= 10) {
        system("cls");
        cout << i++;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}