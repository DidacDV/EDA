#include <iostream>
#include <vector>
using namespace std;

void escriure(vector<string>& v){
    if (v.size() != 0){
        cout << v[0];
        for (int i = 1; i < v.size(); i++){
            cout << v[i];
        }
    }
    cout << endl;
}

void backtracking(vector<string>& v,vector<string>& paraules, vector<bool>&visitats, int i, int n) {
    if (i == n) escriure(v);
    else {
        for (int j = 0; j < 4; j++) {
            v[i] = paraules[j];
            backtracking(v,paraules,visitats,i+1,n);
        }
    }
}



int main () {
    int n;
    cin >> n;
    vector<bool> visitats(n,false);
    vector <string> v(n);
    vector<string> paraules = {"A","C","G","T"};
    
    
    backtracking(v,paraules,visitats,0,n);
}