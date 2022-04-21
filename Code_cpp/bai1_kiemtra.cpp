#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    //chia mang thanh hai phan chenh lech it nhat
    int n;
    cin >> n;
    int arr[n];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    int sum[n];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }
    int ans = 99999;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            int sum1 = sum[l - 1] + sum[n] - sum[r];
            int sum2 = sum[r] - sum[l - 1];
            ans = min(ans, abs(sum1 - sum2));
        }
    }
    cout << ans;
}
