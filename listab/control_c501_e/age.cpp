#include <iostream>
#include <vector>
using namespace std;

struct Persona {
	string nom;
	bool dona;
	int edat;
};

void processing() {
	int n;
	cin >> n;
	vector<Persona> people (n);
	int max_age = 0;
	for (int i = 0; i < n; ++i) {
		cin >> people[i].nom;
		string sex;
		cin >> sex;
		if (sex == "dona") people[i].dona = true;
		else people[i].dona = false;
		cin >> people[i].edat;
		if (not people[i].dona and people[i].edat > max_age) {
			max_age = people[i].edat;
		}
	}
	for (int j = 0; j < n; ++j) {
		if (people[j].dona and people[j].edat < max_age) {
			cout << people[j].nom << " " << people[j].edat << endl;
		}
	}
}	

int main() {
	processing();
}