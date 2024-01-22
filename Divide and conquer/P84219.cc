#include <iostream>
#include <vector>
using namespace std;

int pos(double x, const vector<double>&v, int l, int r) {
    if (l > r) return -1;
    int m = (l+r)/2;

    if(v[m] == x) {
        if (v[m - 1] == x and m - 1 >= l)return pos(x,v,l,m-1);
        else return m;
    }

    if (v[m] > x) return pos(x,v,l,m - 1);
    if (v[m] < x) return pos(x,v,m + 1,r);

}

int first_occurrence(double x, const vector<double>& v) {
    return pos(x,v,0,v.size()-1);
}