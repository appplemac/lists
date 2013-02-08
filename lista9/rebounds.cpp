#include <iostream>
#include <vector>
using namespace std;

void copy_vector(vector<char>& v, vector<char>& w) {
	for (int i = 0; i < w.size(); ++i) {
		v[i] = w[i];
	}
}

void erase_vector(vector<char>& w) {
	for (int i = 0; i < w.size(); ++i) {
		w[i] = '.';
	}
}

void print_vector(vector<char>& v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
	}
	cout << endl;
}

void process(const int vsize, const int exp_num) {
	vector<char> v(vsize, '.');
	vector<char> w(vsize, '.');
	int rnum, rpos;
	cin >> rnum;
	for (int i = 0; i < rnum; ++i) {
		cin >> rpos;
		v[rpos-1] = '>';
	}
	int lnum, lpos;
	cin >> lnum;
	for (int j = 0; j < lnum; ++j) {
		cin >> lpos;
		v[lpos-1] = '<';
	}
	print_vector(v);
	for (int k = 1; k < exp_num; ++k) {
		if (v[0] == '<') v[0] = '>';
		if (v[vsize-1] == '>') v[vsize-1] = '<';
		for (int m = 0; m < vsize; ++m) {
			if (v[m] == '>' and v[m+1] == '<') {
				v[m+1] = '>';
				v[m] = '<';
			}
			if (m > 0 and v[m] == '<') w[m-1] = '<';
			if (m < vsize-1 and v[m] == '>') w[m+1] = '>';
		}
		print_vector(w);
		copy_vector(v, w);
		erase_vector(w);
	}
	cout << endl;
}

int main() {
	int vsize, exp_num;
	while (cin >> vsize >> exp_num) process(vsize, exp_num);
}
