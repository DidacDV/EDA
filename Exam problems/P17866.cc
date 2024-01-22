#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef vector<vector<char>> matriu;
typedef vector<vector<int>> distanciess;

const int N_DIR = 8;

const vector<int> D_X = {2,-2,2,-2,-1,1,-1,1};
const vector<int> D_Y = {-1,-1,1,1,2,2,-2,-2};

bool ok(int x, int y, int n, int m) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

int pastanaga(const matriu &mat, distanciess &d,int x, int y, int n, int m) {
    queue<pair<int,int>> q;
    q.push({x,y});
    d[x][y] = 0;
    while (not q.empty()) {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        if (mat[currx][curry] == 'p') return d[currx][curry];

        for (int i = 0; i < N_DIR; i++) {
            int newx = currx + D_X[i];
            int newy = curry + D_Y[i];
            if (ok(newx,newy,n,m) and mat[newx][newy] != 'X' and d[newx][newy] == -1) {
                q.push({newx,newy});
                d[newx][newy] = d[currx][curry] + 1;
            }
        }
    }
    return -1;
}

int main () {
    int n,m;
    while (cin >> n >> m) {
        matriu mat(n,vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j =0; j < m; j++) cin >> mat[i][j];
        }
        distanciess v(n,vector<int>(m,-1));
        int x,y;
        cin >> x >> y;
        int cont = 0;
        int dist = pastanaga(mat,v,x - 1 ,y - 1,n,m);
        if(dist == -1) cout << "no" << endl;
        else {
            cout << dist << endl; 
        }
    }
}