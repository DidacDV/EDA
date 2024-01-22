#include <iostream>
#include <vector>
using namespace std;

void escriure(vector<int>& v){
    if (v.size() != 0){
        cout << "(" << v[0];
        for (int i = 1; i < v.size(); i++){
            cout << ',' << v[i];
        }
    }
    cout <<  ")" << endl;
}

void permutacions(vector<int> &v, int i, vector <bool> &utilitzats, int n) {
    if (i == n) escriure(v);

    else {
        for (int j = 0;j < n; j++) {
            if (not utilitzats[j]) {
                utilitzats[j] = true;
                v[i] = j + 1;
                permutacions(v,i+1,utilitzats,n);
                utilitzats[j] = false;
            }

        }
    }
}

int main(){

    int n, u;
    cin >> n;

    vector<int> v(n);
    vector <bool> utilitzats(n,false);
    permutacions(v,0,utilitzats, n);

}