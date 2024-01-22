#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        map<string,int> m;
        int total = 0;
        string s; 
        for (int i = 0; i < n; i++) {
            cin >> s;
            ++m[s];
            ++total;
        }
        int n2;
        cin >> n2;
        for (int i = 0; i < n2; i++) {
            cin >> s;
            auto it = m.find(s);
            if (it != m.end()) {
                if (it->second + 1 <= (total - it->second)) ++it->second,++total;
            }
            else {
                ++m[s];
                ++total;
            }
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
        cout << string(20,'-') << endl;
    }
}