#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> row;
typedef vector<row> matrix;

string what(matrix m, int x, int y) {
	bool infinite = false;
	while (not infinite) {
		int curx = x;
		int cury = y;
		char temp = m[x][y];
		if (temp == 'N') --x;
		if (temp == 'S') ++x;
		if (temp == 'W') --y;
		if (temp == 'E') ++y;
		if (temp == ' ') infinite = true;
		if (temp == 'X') return "kaputt";
		if ((x >= m.size() or x < 0) 
			or (y >= m[0].size() or y < 0)) 
				return "escape";
		m[curx][cury] = ' ';
	}
	return "no escape";
}

int main() {
	int a;
	cin >> a;
	for (int k = 0; k < a; ++k) {
		int n;
		cin >> n;
		matrix m(n, vector<char> (n));
		int x, y;
		cin >> x >> y;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> m[i][j];
			}
		}
		cout << what(m, x, y) << endl;
	}
}