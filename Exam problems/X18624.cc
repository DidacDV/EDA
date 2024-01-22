#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool es_vocal(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

void paraules(int n, int m, vector<char>v, vector<char>sol_parcial, int i) {
    if (i == n) {
        for(int j = 0; j < n; ++j) cout << sol_parcial[j];
        cout << endl;
    }
    else {
        for (int x = 0; x < m; ++x) {
            bool vocal_ant = (i > 0 and es_vocal(v[x]) and es_vocal(sol_parcial[i - 1]));
            if (not vocal_ant) {
                sol_parcial[i] = v[x];
                paraules(n,m,v,sol_parcial,i + 1);
            }
        }
    }
}


int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<char>v(m);
        for (int i = 0; i < m; ++i) cin >> v[i];
        sort(v.begin(),v.end());
        vector<char>sol_parcial(n);
        paraules(n,m,v,sol_parcial,0);
        cout << string(10,'-') << endl;
    }
}