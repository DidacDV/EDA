#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

bool valid(int l, int r, int d) {       
    return abs(l - r) <= d;
}

void pous(int n, vector <int> sol, vector <bool> vis, int d) {
    if (sol.size() == n) {
        cout << "(";
        for (int p = 0; p < n; p++) {
            if (p != n - 1) cout << sol[p] << ","; 
            else cout << sol[p] << ")" << endl;
        }
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (not vis[i - 1] and (sol.size() == 0 or (valid(sol[sol.size()-1],i,d)))) {
                sol.push_back(i);
                vis[i-1] = true;
                pous(n,sol,vis,d);
                sol.pop_back();
                vis[i-1] = false;
            }
        }
    }
}

int main() {
    int n,d ;
    cin >> n >> d;
    vector<int> sol;
    vector<bool> vis(n,false);
    pous(n,sol,vis, d);
}