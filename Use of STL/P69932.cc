#include <iostream>
#include <set>
#include <sstream>
using namespace std;


int main() {
	string s;
	while (getline(cin, s)) {
		istringstream ss(s);
		int x;
		set<int> conj;
		while (ss >> x) conj.insert(x);

        int ant = 0, cont = 0;
        auto it = conj.begin();

        if (not conj.empty()) {
            ant = *it;
            ++it;
            ++cont;
        }
        while (it != conj.end()) {
            if (*it > ant and ((ant%2 != 0 and *it%2 == 0) or (ant%2 == 0 and *it%2 != 0))) ++cont; 
            ant = *it;
            ++it;    
        }
        cout << cont << endl;
    }
}