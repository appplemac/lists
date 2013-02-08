#include <iostream> 
#include <vector>
using namespace std;

typedef vector<int> row;
typedef vector<row> matrix; 

void processing() {
	int r, c;
	cin >> r >> c;
	matrix m(r, vector<int> (c));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> m[i][j];
		}
	}
	string s;
	while (cin >> s) {
		if (s == "row") {
			int a;
			cin >> a;
			cout << "row "<< a << ":";
			for (int k = 0; k < m[0].size(); ++k) {
				cout << " " << m[a-1][k];
			}
			cout << endl;
		}
		else if (s == "column") {
			int a;
			cin >> a;
			cout << "column " << a << ":";
			for (int k = 0; k < m.size(); ++k) {
				cout << " " << m[k][a-1];
			} 
			cout << endl;
		}
		else if (s == "element") {
			int a, b;
			cin >> a >> b;
			cout << "element " << a << " " << b << ": "; 
			cout << m[a-1][b-1] << endl;
		}
	}
}

int main() {
	processing();
}