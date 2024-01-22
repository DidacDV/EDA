#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> matriu;
typedef vector<vector<bool>> visitats;

const int N_DIR = 4;

const vector<int> D_X = {1,0,-1,0};
const vector<int> D_Y = {0,1,0,-1};

bool ok(int x, int y, int n, int m) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

int bfs(const matriu &mat,int dist,int xact,int yact,int n,int m) {
    queue<pair<int,int>> q;
    vector<vector<int> > dista(n, vector<int>(m, -1));
    
    q.push({xact,yact});
    dista[xact][yact] = 0;
    dist = -1;
    while (q.size() > 0) {
        int x = q.front().first;
        int y = q.front().second;
        if (mat[x][y] == 't') dist =dista[x][y];
        q.pop();

        for(int i = 0; i < N_DIR; i++) {
            int newx = x + D_X[i];
            int newy = y + D_Y[i];
            if (ok(newx,newy,n,m) and dista[newx][newy] == -1 and mat[newx][newy] != 'X') {
                q.push({newx,newy});
                dista[newx][newy] = dista[x][y] +1;
            }
        }
    }
    return dist;
}


int main() {
    int n, m;

    cin >> n >> m;
	vector<vector<char> > mat(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> mat[i][j]; 
    }
    int dist;

    int x,y;
    cin >> x >> y;
    --x;
    --y;
    dist = bfs(mat,dist,x,y,n,m);
    if(dist > -1) cout << "distancia maxima: " << dist << endl;
    else cout << "no es pot arribar a cap tresor" << endl;

}