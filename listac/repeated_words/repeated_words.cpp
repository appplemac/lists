#include <iostream>
#include <vector>
using namespace std;

struct word {
	string content;
	int appearances;
};

int position(vector<word>& words, string input) {
// Pre: vector<word> and the input string are not empty.
// Post: the position of the structure, the content of which
// 		 is equal to the input, is returned. If such structure
//		 does not exist, the function returns -1.
	for (int i = 0; i < words.size(); ++i) {
		if (words[i].content == input) return i;
	}
	return -1;
}

void print_sum(vector<word>& words, int max_pos) {
	vector<int> v(words.size()+1, 0);
// We've just created the vector that will store our appearance
// counters.
	for (int i = 0; i < max_pos; ++i) {
		v[words[i].appearances] += words[i].content.size();
// Here we sum up the length of the content of the position i
// of the vector to the position of v, which contains
// the counter for its appearance case. 
	}
	for (int j = 1; j < v.size(); ++j) {
		if (v[j] != 0) {
// We have to print only the lines with non-zero length.
			cout << j << " repetition(s): " << v[j] << endl;
		}
	}
}



void processing(int cases) {
	vector<word> words(cases);
// We declare a vector of the size "cases" because
// all the words can be different, this would be
// the worst case. Not very memory efficient in all
// other cases, but alsolutely secure.
	int j = 0;
	for (int i = 0; i < cases; ++i) {
		string input;
		cin >> input;
		int pos = position(words, input);
		if (pos == -1) {
// If such string does not exist, we need to create it,
// setting a free position's fields in the vector 
// to the input value and, as long as it is the first
// appearance of the string, one respectively.
			words[j].content = input;
			words[j].appearances = 1;
			++j;
		}
		else {
// Otherwise there is such string in the vector, so we
// have to increment the appearance counter.
			++words[pos].appearances;
		}
	}
	print_sum(words, j);
}

int main() {
// Simply call the processing function with the 
// case condition as an argument.
	int cases;
	while (cin >> cases) {
		processing(cases);
		cout << endl;
	}
}