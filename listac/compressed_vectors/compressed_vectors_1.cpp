#include <iostream>
#include <vector>
using namespace std;

struct Parell {
    int valor;
    int pos;
};

typedef vector<Parell> Vec_Com;

Vec_Com suma(const Vec_Com& v1, const Vec_Com& v2) {
    int n1 = v1.size();
    int n2 = v2.size();
    Vec_Com v(n1+n2);
    
    int i = 0;
    int j = 0;
    int cont = 0;
    while (i < n1 and j < n2) {
        if (v1[i].pos < v2[j].pos) {
            v[cont].valor = v1[i].valor;
            v[cont].pos = v1[i].pos;
            ++i;
            ++cont;
        }
        else if (v1[i].pos > v2[j].pos) {
            v[cont].valor = v2[j].valor;
            v[cont].pos = v2[j].pos;
            ++j;
            ++cont;
        }
        else if (v1[i].valor + v2[j].valor != 0) {
            v[cont].valor = v1[i].valor + v2[j].valor;
            v[cont].pos = v1[i].pos;
            ++i; ++j;
            ++cont;
        }
        else {
            ++i; ++j;
        }
    }
    
    while (i < n1) {
        v[cont].valor = v1[i].valor;
        v[cont].pos = v1[i].pos;
        ++i;
        ++cont;
    }
    
    while (j < n2) {
        v[cont].valor = v2[j].valor;
        v[cont].pos = v2[j].pos;
        ++j;
        ++cont;
    }
    
    Vec_Com v_com(cont);
    for (int k = 0; k < cont; ++k) {
        v_com[k] = v[k];
    }
    
    return v_com;
}

void llegeix(Vec_Com& v) {
    int n = v.size();
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].valor >> c >> v[i].pos;
    }
}

void escriu(Vec_Com& v) {
    int n = v.size();
    cout << n;
    for (int i = 0; i < n; ++i) {
        cout << " " << v[i].valor << ";" << v[i].pos;
    }
    cout << endl;
}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        Vec_Com v1(n);
        llegeix(v1);
        
        int m;
        cin >> m;
        Vec_Com v2(m);
        llegeix(v2);
        
        Vec_Com v = suma(v1,v2);
        escriu(v);
    }
}