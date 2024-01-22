#include <iostream>
#include <map>
using namespace std;


int main() {
  map<string, int> M;
  char c;
  while (cin >> c) {
    if (c == 'N') {
      cout << "number: " << M.size() << endl;
    }
    else if (c == 'D') {
      string nif;
      int money;
      cin >> nif >> money;
      M[nif] += money;
    }
    else if (c == 'Q') {
      string nif;
      cin >> nif;
      auto it = M.find(nif);
      if (it != M.end()) cout << it->second << endl;
      else cout << -1 << endl;
    }
    else if (c == 'P') {
        bool primer = true;
      for (auto &it: M) {
        if (((it.first[it.first.length() - 2]) - '0')%2 == 0)  {
            if (not primer) cout << " " << it.first;
            else if (primer) primer = false, cout << it.first;
        }
      }
      cout << endl;
    }
    else { // c == 'L'
      if (M.size() == 0) cout << "NO LAST NIF" << endl;
      else {
        auto it = M.end(); --it;
        cout << it->first << " " << it->second << endl;
      }
    }
  }
}
