#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<char> v = {'x','y','z'};

int allunyat(const vector<vector<int>> &g) {
    int n = g.size();
    queue<int> q;
    q.push(0);
    int max = 0;
    int vertex = 0;
    vector<int> dist(n,-1);
    dist[0] = 0;
    while (not q.empty()) {
        int seguent = q.front();
        q.pop();
        for (int v = 0; v < g[seguent].size(); ++v) {
            int vert = g[seguent][v];
            if (dist[vert] == -1) {
                dist[vert] = dist[seguent] + 1;
                q.push(vert);
            }
        }
    }
    int res = 0;
    for (int v = 1; v < n; ++v) {
        if (dist[v] != -1 and dist[v] > dist[res]) {
            res = v;
        }
    }
    return res;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> g(n);

        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cout << allunyat(g) << endl;
    }
}