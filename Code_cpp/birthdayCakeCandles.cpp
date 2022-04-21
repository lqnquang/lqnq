#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>candles;
	candles.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> candles[i];
	}
	int tallest_candle = candles[0], count_candle = 1;
	for (int i = 1; i < n; i++) {
		if (candles[i] > tallest_candle) {
            tallest_candle = candles[i];
            count_candle = 1;
        } else {
        	if (candles[i] == tallest_candle) {
            	count_candle++;
        	}
		}
	}
	cout << count_candle << " " << tallest_candle;
}
