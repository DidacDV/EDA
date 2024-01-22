#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;


void concatenades(vector<string> s, vector<string> sol_parcial, vector<bool> &vis, int k) {
    if (k == s.size())  {
        for (int m = 0; m < k; ++m) {
            cout << sol_parcial[m];
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < s.size(); i++) {
            if (not vis[i] and (sol_parcial.size() == 0 or sol_parcial[k - 1].back() != s[i][0])) {
                sol_parcial.push_back(s[i]);
                vis[i] = true;
                concatenades(s,sol_parcial,vis,k + 1);
                sol_parcial.pop_back();
                vis[i] = false;
            }
        }
    } 
}

int main() {
    int n;
    while(cin >> n) {
        vector<string>v(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v[i] = s;
        }
        vector<string> sol;
        vector<bool> vis(n,false);
        concatenades(v,sol,vis, 0);
    }

}