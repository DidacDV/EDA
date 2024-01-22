#include <iostream>
#include <vector>
using namespace std;

void escriure(vector<int>& v){
    if (v.size() != 0){
        cout << v[0];
        for (int i = 1; i < v.size(); i++){
            cout << ' ' << v[i];
        }
    }
    cout << endl;
}

void zerosiuns(int i, vector<int> &v, int zeros, int uns){

    if (i == v.size()) escriure(v);
    else {
        if (0 < zeros) {
            v[i] = 0;
            zerosiuns(i + 1, v, zeros - 1, uns);
        }
        if (0 < uns) {
            v[i] = 1;
            zerosiuns(i+1,v,zeros,uns - 1);
        }
    }

}

int main(){

    int n, u;
    cin >> n >> u;
    int zeros = n - u;
    int uns = u;
    vector<int> v(n);
    zerosiuns(0, v, zeros,uns);

}