#include <iostream>
#include <vector>
using namespace std;

int max_vec(vector<int> v) {
	int max = v[0];
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] > max) max = v[i];
	}
	return max;
}

int evaluate(string a) {
	int result = 0;
	for (int i = 0; i < a.size(); ++i) {
		result += a[i]-'a';
	}
	return result;
}

void processing(int a) {
	vector<int> values(a);
	vector<string> raw(a);
	for (int i = 0; i < a; ++i) {
		string word;
		cin >> word;
		raw[i] = word;
		values[i] = evaluate(word);
	}
	for (int j = 0; j < a; ++j) {
		if (values[j] < max_vec(values)) cout << raw[j] << endl;
	}
	cout << "----------" << endl;
}

int main() {
	cout << "----------" << endl;
	int a;
	while (cin >> a) processing(a);
}
