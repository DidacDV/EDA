#include <iostream>
#include <map>
using namespace std;


int main() {
    map<string,int> m;
    string s;
    while(cin >> s) {
        map<string,int>::iterator it;
        if (s == "minimum?") {
            if (m.empty()) cout << "indefinite minimum" << endl;
            else {
                it = m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            } 

        }
        else if (s == "maximum?") {
            if (m.empty()) cout << "indefinite maximum" << endl;
            else {
                it = m.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if (s == "delete") {
            string ss;
            cin >> ss;
            it = m.find(ss);
            if (it != m.end()) {
                if (it->second != 1) m[ss] -= 1;
                else m.erase(ss);
            }
        }
        else if (s == "store") {
            string ss;
            cin >> ss;
            it = m.find(ss);
            if (it != m.end()) {
                m[ss] += 1;
            }
            else m.insert(make_pair(ss,1));
        }
    }
}