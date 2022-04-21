#include <iostream>
using namespace std;

int solve(int numPage, int page);

int main() {
    int number_of_page;
    int page;
    cout << "Number of page: ";
    cin >> number_of_page;
    cout << "Page number: ";
    cin >> page;
    cout << "The minimum number of pages to turn: " << solve(number_of_page, page);
    return 0;
}

int solve(int numPage, int page) {
    numPage = numPage / 2 + 1;
    page = page / 2 + 1;
    if (page >= numPage / 2 + 1) return (numPage - page);
    else return (page - 1);
}