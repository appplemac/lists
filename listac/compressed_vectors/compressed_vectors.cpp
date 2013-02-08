#include <iostream>
#include <vector>
using namespace std;

struct Parell {
	int valor;
	int pos;
};

typedef vector<Parell> Vec_Com;

Vec_Com suma(const Vec_Com& v1, const Vec_Com& v2) {
	int s1 = v1.size();
	int s2 = v2.size();
	Vec_Com v3(s1+s2);
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < s1 and j < s2) {
		if (v1[i].pos < v2[j].pos) {
			v3[k].valor = v1[i].valor;
			v3[k].pos = v1[i].pos;
			++i;
			++k;
		}
		else if (v1[i].pos > v2[j].pos) {
			v3[k].valor = v2[j].valor;
			v3[k].pos = v2[j].pos;
			++j;
			++k;
		}
		else if (v1[i].valor + v2[j].valor != 0) {
			v3[k].valor = v1[i].valor + v2[j].valor;
			v3[k].pos = v1[i].pos;
			++i;
			++j;
			++k;
		}
		else {
			++i;
			++j;
		}
		while (i < s1) {
			v3[k].valor = v1[i].valor;
			v3[k].pos = v1[i].pos;
			++i;
			++k;
		}
		while (j < s2) {
			v3[k].valor = v2[j].valor;
			v3[k].pos = v2[j].pos;
			++j;
			++k;
		}
		Vec_Com result(k);
		for (int l = 0; l < k; ++l) {
			result[l] = v3[l];
		}
		return result;
	}
}

void llegeix(Vec_Com& v) {
	int n = v.size();
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> v[i].valor >> c >> v[i].pos;
	}
}

void escriu(Vec_Com& v) {
   cout << v.size();
   for (int i = 0; i < v.size();++i) {
       cout << ' ' << v[i].valor << ";" << v[i].pos;
   }
   cout << endl;
}


int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int d1;
        cin >> d1;
        Vec_Com v1(d1);
        llegeix(v1);
        int d2;
        cin >> d2;
        Vec_Com v2(d2);
        llegeix(v2);
        Vec_Com v = suma(v1, v2);
        escriu(v);
    }
}
