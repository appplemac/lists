#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int tmp = a%b; // the simple gcd function
		a = b; // copyright Euclid (c) 300 BC
		b = tmp;
	}
	if (a < 0) return -a; // this is to override the problems
	return a; // with the sign of gcd of two negative numbers  
}

void simplify(int& a, int&b) {
	int g = gcd(a, b);
	if (g != 1) {
		a = a/g; // here we simplify the rational, if possible
		b = b/g;
	}
	if (b < 0) { 		// we will put the sign of b to a
		a = a*(-1);		// this way print(a,b) will not have
		b = b*(-1);		// any problems with the sign

	}
}

void print(int a, int b) {
	if ((a/b)*b != a) cout << a << "/" << b;
	else cout << a/b;
	cout << endl;
}

void processing() {
	int a, b;
	cin >> a >> b;
	simplify(a, b);
	print(a, b);
	string op;
	while (cin >> op) {
		int c, d;
		cin >> c >> d;
		int e, f;
		if (op == "add") {
			e = a*d + b*c;
			f = b*d;
		}
		else if (op == "substract") {
			e = a*d - b*c;
			f = b*d;
		}
		else if (op == "multiply") {
			e = a*c;
			f = b*d;
		}
		else if (op == "divide") {
			e = a*d; // divide means multiply by the reversed rational
			f = b*c;
		}
		simplify(e, f);
		print(e, f);
		a = e;
		b = f;
	}
}

int main() {
	processing();
}