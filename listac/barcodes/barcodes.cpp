#include <iostream>
using namespace std;

int check_digit(string ean) {
	int even = 0;
	int odd = 0;
	int i = 11;
	while (i >= 0) {
		odd += (ean[i]-'0');
		--i;
		if (i >= 0) {
			even += (ean[i]-'0');
			--i;
		}
	}
	int sum = odd*3 + even;
	if (sum%10 == 0) return 0;
	return 10-(sum%10);

}

int main() {
	string a;
	while (cin >> a) {
		cout << a << check_digit(a) << endl;
	}
}