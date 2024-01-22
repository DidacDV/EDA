#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;
const int inf = numeric_limits<int>::max();
const int N_DIR = 8;
const vector<int> D_X = {2,-2,2,-2,-1,1,-1,1};
const vector<int> D_Y = {-1,-1,1,1,2,2,-2,-2};

bool ok(int x, int y, int n, int m) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

int buscaFlors(const vvc &prat, int n, int m, int xini, int yini, double &mitj) {
    vvi distancies(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    int flors = 0;
    q.push({xini,yini});
    distancies[xini][yini] = 0;
    while (not q.empty()) {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (prat[x][y] == 'F') {
            ++flors;
            mitj += distancies[x][y];
        }
        for (int i = 0; i < N_DIR; i++) {
            int newx, newy;
            newx = D_X[i] + x;
            newy = D_Y[i] + y;
            if (ok(newx,newy,n,m) and distancies[newx][newy] == -1 and prat[newx][newy] != 'a') {
                q.push({newx,newy});
                distancies[newx][newy] = distancies[x][y] + 1;
            } 
        }
    }
    return flors;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    int n, m;
    cin >> n >> m;
    vvc prat(n,vector<char>(m));
    int xini, yini;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> prat[i][j];
            if (prat[i][j] == 'C') xini = i, yini = j;
        }
    }
    int flors = 0;
    double mitj;
    flors = buscaFlors(prat,n,m,xini,yini, mitj);
    if (flors == 0) cout << "el cavall no pot arribar a cap flor" << endl;
    else {
        cout << "flors accessibles: " << flors << endl << "distancia mitjana: " << mitj/flors << endl;
    }
}