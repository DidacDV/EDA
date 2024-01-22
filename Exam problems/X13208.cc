#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

typedef vector<vector<int>> vi;
const int inf = numeric_limits<int>::max();
vector<int> d_x = {1,0,-1,0};
vector<int> d_y = {0,1,0,-1};

bool borde(int x, int y, int n) {
    return x == 0 or y == 0 or x == n - 1 or y == n -1;
}

int tauler(const vi &v) {
    int n  =v.size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
    vector<vector<int>> distancies(n,vector<int>(n,inf));
    vector<vector<bool>> marked(n,vector<bool>(n,false));
    q.push({v[n/2][n/2],{n/2,n/2}});
    distancies[n/2][n/2] = v[n/2][n/2];
    while (not q.empty()) {
        int x = q.top().second.first;
        int y = q.top().second.second;
        int dist = q.top().first;
        q.pop();
        if (not marked[x][y]) {
            marked[x][y] = true;
            if (borde(x,y,n)) return dist;
            for (int i = 0; i < 4; i++) {
                int newx = x + d_x[i];
                int newy = y + d_y[i];
                if (distancies[newx][newy] > dist + v[newx][newy]) {
                    distancies[newx][newy] = dist + v[newx][newy];
                    q.push({distancies[newx][newy],{newx,newy}});
                }
            }
        }
    }
    return -1;
}

int main() {
    int n;
    while (cin >> n) {
        vi v(n,vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> v[i][j];
        }
        cout << tauler(v) << endl;
    }
}