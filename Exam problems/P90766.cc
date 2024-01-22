#include <iostream>
#include <vector>
using namespace std;
typedef vector<char> matt;
typedef vector<matt> mat;

typedef vector<bool> vis;
typedef vector<vis> visitats;

const int N_DIR = 4;
const vector<int> D_X = {1,0,-1,0};
const vector<int> D_Y = {0,1,0,-1};

int tresors(const mat &matriu, visitats &vs, int x, int y, int n, int m) {
    int tres = 0;
    if (vs[x][y]) return 0;
    vs[x][y] = true;
    if (matriu[x][y] == 't') ++tres;
    for (int i = 0; i < N_DIR; i++) {
        int next_x = x+D_X[i];
        int next_y = y+D_Y[i];
        if (next_x < n and next_y < m and next_x>= 0 and next_y >= 0 and matriu[next_x][next_y] != 'X') {
            tres = tres + tresors(matriu, vs, next_x, next_y, n, m);
        }
    }
    return tres;
}

int main () {
    int n, m;
    cin >> n >> m;
    mat matriu(n,matt(m));
    visitats vs(n,vis(m,false));


    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> matriu[i][j];
    }
    int x,y;
    cin >> x >> y;
    int tres = 0;
    cout << tresors(matriu, vs, x - 1,y - 1, n, m) << endl;

}