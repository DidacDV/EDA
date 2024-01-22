#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

bool valid(int l, int r, int m) {       // l xi r x(i+2) m x(i+1)
    return l + r <= 2*m;
}

void pous(int n, vector <int> sol, vector <bool> vis) {
    if (sol.size() == n) {
        cout << "(";
        for (int p = 0; p < n; p++) {
            if (p != n - 1) cout << sol[p] << ","; 
            else cout << sol[p] << ")" << endl;
        }
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (not vis[i - 1] and (sol.size() <= 1 or (valid(sol[sol.size() - 2], i, sol.back())))) {
                sol.push_back(i);
                vis[i-1] = true;
                pous(n,sol,vis);
                sol.pop_back();
                vis[i-1] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> sol;
    vector<bool> vis(n,false);
    pous(n,sol,vis);
}