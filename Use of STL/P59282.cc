#include <iostream>
#include <queue>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	string op;
	priority_queue<int, vector<int>, greater<int>> p;
    int max;
    double mitj;
    mitj = 0.0;
    while (cin >> op) {
        if (op == "number") {
            int n;
            cin >> n;
            if (p.empty() or n > max) max = n;
                p.push(n);
                mitj += n;
        }
		else if(op == "delete" and !p.empty()) {
			mitj -= p.top();
			p.pop();
		}
        if (p.empty()) cout << "no elements" << endl;
        else {
            cout << "minimum: " << p.top() << ", maximum: " << max << ", average: " << mitj/p.size() << endl;
        }
    }
}