#include <iostream>
#include <set>
using namespace std;


int main() {
    set<string> t;
    string s;
    cin >> s;
    if (s != "END") {
        cout << s << endl;
        t.insert(s);
        auto it = t.begin();
        while (cin >> s and s != "END") {
                t.insert(s);
                if (t.size()%2 == 0 and s < *it) --it;
                if (t.size()%2 != 0 and s > *it) ++it;
                cout << *it << endl;
        }
    }
}