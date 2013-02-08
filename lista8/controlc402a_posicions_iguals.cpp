#include <iostream>
using namespace std;

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int posicions_iguals(string s1, string s2) {
	int c = 0;
	for (int i = 0; i < min(s1.length(), s2.length()); ++i) {
		if (s1[i] == s2[i]) ++c;
	}
	return c;
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		cout << posicions_iguals(s1, s2) << endl;
	}
}
