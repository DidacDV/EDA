#include <iostream>
#include <vector>

using namespace std;
vector<char> v = {'x','y','z'};

void xyz(int n, int c, vector<char> &sol, int i, int cont) {
    if (i == n) {
        for(int j = 0; j < n; j++) cout << sol[j];
        cout << endl;
    }
    else {
        for (int x = 0; x < 3; ++x) {
            bool repetit = (i > 0 and sol[i - 1] == v[x]);
            int nou;
            if (repetit) nou = cont + 1;
            else nou = 1;
            if (nou <= c) {
                sol[i] = v[x];
                xyz(n,c,sol,i+1,nou);
            } 
        }
    }
}

int main() {
    int c, n;

    while (cin >> n >> c) {
        vector <char> sol(n);
        int i = 0;
        int cont = 0;
        xyz(n,c,sol,0, 0);
        cout <<  "--------------------" << endl;
    }
}