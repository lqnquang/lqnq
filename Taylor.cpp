#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double x, sum = 1, oldsum = 0, i = 1, k = 1;
    cin >> x;
    while (sum - oldsum > 0.001) {
        oldsum = sum;
        k = k * x / i;
        sum += k;
        i++;
    }
    cout << setprecision(4) << fixed << sum;
    return 0;
}