#include <iostream>
//rock: r
//player: y
//space: e
// Thuat toan:
//	|e	|y	|r	|
//	|e	|e	|e	|
#include <vector>
using namespace std;
int main() {
	int w, h;
	cin >> w >> h;
	vector< vector<char> >magicWorld;
	magicWorld.resize(h);
	for (int i = 0; i < h; i++) {
		magicWorld[i].resize(w + 2);
		for (int j = 1; j <= w; j++) {
			cin >> magicWorld[i][j];
		}
	}
	
	for (int i = 0; i < h - 1; i++) {
		for (int j = 1; j <= w; j++) {
			if (magicWorld[i][j] == 'Y') {
				if (magicWorld[i + 1][j] == 'E') magicWorld[i + 1][j] = 'Y';
				if (magicWorld[i + 1][j - 1] == 'E' && magicWorld[i][j - 1] == 'E') magicWorld[i + 1][j - 1] = 'Y';
				if (magicWorld[i + 1][j + 1] == 'E' && magicWorld[i][j + 1] == 'E') magicWorld[i + 1][j + 1] = 'Y';
			}
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= w; j++) {
			cout << magicWorld[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int j = 0; j <= w; j++) {
		if (magicWorld[h - 1][j] == 'Y') {
			cout << "YES" << endl;
			return 0;
		}	
	}	
	cout << "NO" << endl;
	return 0;
}
