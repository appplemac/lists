#include <iostream>
using namespace std;

bool is_vowel(char a) {
	if (a == 'a' or a =='e' or a == 'i' or a == 'o' or a == 'u') return true;
	return false;
}

bool is_alternant(string s) {
	bool alternant = true;
	int i = 0;
	while (i < s.size()-1 and alternant) {
		if ((is_vowel(s[i]) and is_vowel(s[i+1])) or
			(not is_vowel(s[i]) and not is_vowel(s[i+1]))) {
			alternant = false;
		}
		++i;
	}
	return alternant;
}

int alternant_cases(int a) {
	if (a == 0) return 0;
	int result = 0;
	string first, second;
	cin >> first;
	for (int i = 0; i < a-1; ++i) {
		cin >> second;
		if ((is_alternant(first) and not is_alternant(second)) or 
			(not is_alternant(first) and is_alternant(second))) ++result;
			first = second;
	}
	return result;
}

int main() {
	int a;
	while (cin >> a) {
		cout << alternant_cases(a) << endl;
	}
}