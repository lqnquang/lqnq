#include <fstream>
#include <iostream>
using namespace std;
int main() {
    ofstream outfile("outfile.txt");
    if (outfile.is_open()) {
        outfile << "What \n";
        outfile << "the \n";
        outfile.close();
    } else
        cout << "Unable to open file";
    string line;
    ifstream infile("infile.txt");
    if (infile.is_open()) {
        while (getline(infile, line)) {
            cout << line << '\n';
        }
        infile.close();
    } else 
        cout << "Unable to open file";
    return 0;
}