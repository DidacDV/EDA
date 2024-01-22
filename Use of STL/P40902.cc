#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,int> m;
    string s;
    while (cin >> s) {
        map<string,int>::iterator it;
        string a;
        cin >> a;
        if (a == "enters") {
            it = m.find(s);
            if (it == m.end()) m.insert(make_pair(s,0));
            else cout << s << " is already in the casino" << endl;
        }
        else if (a == "leaves") {
            it = m.find(s);
            if (it != m.end()) {
                cout << s << " has won " << it->second <<  endl;
                m.erase(it);
            }               
            else cout << s << " is not in the casino" << endl;
        }
        else if (a == "wins") {
            int n;
            cin >> n;
            it = m.find(s);
            if (it != m.end()) {
                m[s] += n;
            }
            else cout << s << " is not in the casino" << endl;
        }
    }
    cout << "----------" << endl;
    map<string,int>::iterator it = m.begin();
    while (it != m.end()) {
        cout << it->first << " is winning " << it->second << endl;
        ++it;
    }
}