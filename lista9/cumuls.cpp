#include <iostream>
#include <vector>
using namespace std;

bool is_cumulative(int pos, const vector<int>& v) {
	int sum = 0;
	for (int i = pos-1; i >= 0; --i) {
		sum += v[i];
		if (v[pos] == sum) return true;
	}
	return false;
}

vector<bool> cumul_row(const vector<int>& v) {
	int a = v.size();
	vector<bool> cumul(a);
	for (int j = 0; j < a; ++j) {
		if (is_cumulative(j, v)) cumul[j] = true;
	}
	return cumul;
}

int max_cons_cumul(vector<bool> v) {
	int max = 0;
	int local_max = 0;
	for (int i = 0; i < v.size(); ++i) {
		while (i < v.size() and v[i] == true) {
			++local_max;
			++i;
		}
		if (local_max > max) max = local_max;
		local_max = 0;
	}
	return max;
}

int main() {
	int a;
	while (cin >> a) {
		vector<int> v(a);
		for (int i = 0; i < a; ++i) {
			cin >> v[i];
		}
		cout << max_cons_cumul(cumul_row(v)) << endl;
	}
}