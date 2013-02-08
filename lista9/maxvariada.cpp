#include <iostream>
#include <vector>
using namespace std;

int diff_letters(string a) {
	int result = 1;
	for (int i = 1; i < a.size(); ++i) {
		int j = i-1;
		bool diff = true;
		while (j >= 0 and diff) {
			if (a[j] == a[i]) diff = false;
			--j;
		}
		if (diff) ++result;
	}
	return result;
}

string varied(int case_num) {
	if (case_num == 0) return "";
	int max = 0;
	int pos_max = 0;
	vector<string> v(case_num);
	for (int i = 0; i < case_num; ++i) {
		cin >> v[i];
	}
	for (int j = 0; j < case_num; ++j) {
		if (diff_letters(v[j]) > max) {
			max = diff_letters(v[j]);
			pos_max = j;
		}
	}
	return v[pos_max];
}

int main() {
	int case_num;
	while (cin >> case_num) {
		cout << varied(case_num) << endl;
	}
}
