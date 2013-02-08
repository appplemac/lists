#include <iostream>
#include <vector>
using namespace std;

void sieve(vector<int>& v) {
	for (int i = 2; i < v.size(); ++i) {
		int k = 2;
		while (i*k < v.size()) {
			v[i*k] = 0;
			++k;
		}
	}
}

int main() {
	vector<int> v(7920);
	for (int j = 0; j < v.size(); ++j) {
		v[j] = j;
	}
	sieve(v);
	int a;
	while (cin >> a) {
		bool started = false;
		for (int i = 2; i < v.size() and a > 0; ++i) {
			if (v[i] != 0) {
				if (started) cout << ",";
				started = true;
				cout << v[i];
				--a;
			}
		}
		cout << endl;
	}
}