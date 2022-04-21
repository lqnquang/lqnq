#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    /*vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) 
        cin >> arr[i];
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] * arr[i + 1] >= 0) {
            arr.erase(arr.begin() + i);
            i--;
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << arr.size() << endl;*/
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int dp[n + 1];
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] * a[j] < 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            } else {
                dp[i] = max(dp[i], dp[j]);
            }
        }
    }
    cout << dp[n];
}