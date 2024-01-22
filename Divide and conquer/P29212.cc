#include <iostream>
#include <vector>
using namespace std;


int exp(int n, int k, int m) {
    int r = 1;
    while (k > 0) {
        if (k %2 == 1) r = (r*n) % m;
        k = k >> 1;
        n = (n*n)%m;


    }

    return r;
}





int main() {
    int n, k, m;
    while(cin >> n >> k >> m) cout << exp(n,k,m) << endl;
}