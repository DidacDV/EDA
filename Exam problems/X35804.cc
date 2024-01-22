#include <iostream>
#include <map>
using namespace std;


struct Info {
  string code;
  int price;
};



int main() {
  map<int, Info> M;
  char c;
  while (cin >> c) {
    if (c == 'n') {
        cout << "num: " <<  M.size() << endl;
    }
    else if (c == 'u') {
      string code;
      int length, price;
      cin >> code >> length >> price;
      M[length] = {code,price};
    }
    else if (c == 'q') {
        int length ;
        cin >> length;
        if (M.count(length) == 1) cout << M[length].price << endl;
        else cout << -1 << endl;
    }
    else if (c == 'p') {
        cout << string(10, '-') << endl;

        for (auto &it: M) {
            cout << it.second.code << " " << it.first << " " << it.second.price << endl;
        }
        cout << string(10, '*') << endl;
    }
    else { // c == 's'
    if (M.size() < 2) cout << "no" << endl;
    else {
        auto it = M.begin();
        ++it;
        cout << it->second.code << " " << it->first << " " << it->second.price << endl;
        }
    }
  }
}