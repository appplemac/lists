#include <iostream>
#include <string>
using namespace std;

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

string gira(string s) {
	for (int i = 0; i < s.length()/2; ++i) {
		char temp = s[i];
		s[i] = s[s.length()-i-1];
		s[s.length()-i-1] = temp;
	}
	return s;
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		bool equal1 = true;
		bool equal2 = true;
		for (int i = 0; i < min(s1.length(), s2.length()) and equal1; ++i) {
			if (s1[i] != s2[i]) equal1 = false;
		}
		string s3 = gira(s2);
		for (int i = 0; i < min(s1.length(), s2.length()) and equal2; ++i) {
			if (s1[i] != s3[i]) equal2 = false;
		}
		if (equal1 or equal2) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
