#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int min, max;
    cout << "Min, Max: ";
    cin >> min >> max;
    for (int i = 0; i <= 50; i++) {
        //srand(time(NULL));
        int randomNum = rand() % (max - min + 2);
        cout << randomNum << " ";
    }
    return 0;
}