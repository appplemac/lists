#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> row;
typedef vector<row> matrix;

bool is_increasing(matrix& m) {
	bool increasing = true;
	bool end = false;
	int i = 0;
	int j = 0;
	int first = m[i][j];
	end = (i == m.size()-1 and j == m[0].size()-1);
	while (not end and increasing) {
		if (j%2 == 0) {
			if (i == m.size()-1) {
				++j;
			}
			else ++i;
		}
		else {
			if (i == 0) {
				++j;
			}
			else --i;
		}
 		int next = m[i][j];
		if (next <= first) increasing = false;
		first = next;
		if (j%2 == 0) {
			end = (i == m.size()-1 and j == m[0].size()-1);
		}
		else {
			end = (i == 0 and j == m[0].size()-1);
		}
	}
	return increasing;
}

int main() {
	int r, c;
	int casenum = 1;
	while (cin >> r >> c) {
		matrix m(r, vector<int> (c));
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; j++){
				cin >> m[i][j];
			}
		}
		cout << "matriu " << casenum << ": ";
		if (is_increasing(m)) cout << "si" << endl;
		else cout << "no" << endl;
		++casenum;
	}
}