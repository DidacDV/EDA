#include <iostream>
#include <queue>
using namespace std;


int main() {
    char c;
    priority_queue<int> q;
    while (cin >> c) {
        if (c == 'S') {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (c == 'A' and not q.empty()) {
            cout << q.top() << endl;
        }
        else if (c == 'R' and not q.empty()) {
            q.pop();
        }
        else if (c == 'I') {
            int x;
            cin >> x;
            if(not q.empty()) {
                x += q.top();
                q.pop();
                q.push(x);
            }
            else cout << "error!" << endl;
        }
        else if (c == 'D') {
            int x;
            cin >> x;
            if (not q.empty()) {
                x = q.top() - x;
                q.pop();
                q.push(x);
            }
            else cout << "error!" << endl;
        }
        else cout << "error!" << endl;
    }
}