#include <iostream>
#include <vector>
using namespace std;

void processing(int a, int b) {
	vector<int> v(b);
	for (int i = 0; i < b; ++i) {
		v[i] = 0;
	}
	for (int j = 0; j < a; ++j) {
		int c;
		cin >> c;
		++v[c];
	}
	for (int k = 0; k < b; ++k) {
		cout << k << ':' << v[k];
		if (k == b-1) cout << '.' << endl;
		else cout << ',' << ' ';
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	processing(a, b);
}
