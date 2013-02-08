#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> row;
typedef vector<row> matrix;

bool ok(matrix m) {
	int imin = -1;
	int imax = -1;
	int jmin = -1;
	int jmax = -1;
	for (int i = 0; i < m.size(); ++i) {
		for (int j = 0; j < m.size(); ++j) {
			if (m[i][j] == 0) {
				if (imin == -1) imin = i;
				if (imin > i) imin = i;
				if (imax < i) imax = i;

				if (jmin == -1) jmin = j;
				if (jmin > j) jmin = j; 
				if (jmax < j) jmax = j;
			}
		}
	}
	if (imin == -1) return true;
	for (int k = imin; k <= imax; ++k) {
		for (int l = jmin; l <= jmax; ++l) {
			if (m[k][l] != 0) return false;
		}
	}
	return true;
}

int main() {
	int a;
	cin >> a;
	for (int i = 0; i < a; ++i) {
		int n;
		cin >> n;
		matrix m(n, vector<int> (n));
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				cin >> m[j][k];
			}
		}
		if (ok(m)) cout << "ok" << endl;
		else cout << "ko" << endl;
	}
}