#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double calculate (double num1, char operat, double num2) {
    double result;
    switch (operat) {
        case '+': {
            result = num1 + num2;
            break;
        }
        case '-': {
            result = num1 - num2;
            break;
        }
        case '*': {
            result = num1 * num2;
            break;
        }
        case '/': {
            result = num1 / num2;
            break;
        }
    }
    return result;
}
double mySin(double x)
{
    while (x > 2 * M_PI) {
        x -= 2 * M_PI;
    }
    double result = x, temp = 1;
    int n = 1;
    while (temp > 0.00001) {
        temp = 1;
        for (int j = 1; j <= 2 * n + 1; j++)
            temp = temp * x / j;
        if (n % 2 == 0) result += temp;
        else result -= temp;
        n++;
    }
    return result;
}
double myCos(double x) 
{
    while (x > 2 * M_PI) {
        x -= 2 * M_PI;
    }
    double result = 1, temp = 1;
    int n = 1;
    while (temp > 0.00001) {
        temp = 1;
        for (int j = 1; j <= 2 * n; j++)
            temp = temp * x / j;
        if (n % 2 == 0) result += temp;
        else result -= temp;
        n++;
    }
    return result;
}
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else {
        double result = 1.00;
        while (abs(result * result - x) / x >= 0.0000001) {
            result = 1.00 / 2 * (result + x / result);
        }
        return result;
    }
}
int main() {
	/*double num1, num2;
	char operat;
	cin >> num1;
    cin >> operat;
    cin >> num2;
	cout << fixed << setprecision(2) << calculate(num1, operat, num2);*/
    double x;
    cin >> x;
    cout << mySqrt(x) << endl;
}
