#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> VVC;
typedef vector<vector<bool>> VVB;

const vector<int> D_X = {1,0,-1,0,1,1,-1,-1};
const vector<int> D_Y = {0,1,0,-1,-1,1,1,-1};

const int N_DIR_H_V = 4;    //num direccions horitz i vertical
const int N_DIR_D = 8;      //diagonal + horitz i vertical

bool pos_ok(int x, int y, int f, int c) {
    return x > 0 and x < f and y > 0 and y < c;
}

bool fantasmes(const VVC &tauler, int x, int y, int f, int c) {
    for (int i = 0; i < N_DIR_D; i++) {     //mirem que no hi hagi fantasmes
        int xnew = x +D_X[i];
        int ynew = y + D_Y[i];
        if ((pos_ok(xnew,ynew,f,c) and tauler[xnew][ynew] == 'F')) return true;
    }
    return false;
}

bool bfs(const VVC &tauler, VVB &visitats, int xini, int yini, int f, int c) {
    if (fantasmes(tauler,xini,yini,f,c)) return false;       //mirem si hi ha un fantasma al principi
    queue<pair<int,int>> q;
    q.push({xini,yini});
    visitats[xini][yini] = true;
    while (not q.empty()) {
        int xact = q.front().first;
        int yact = q.front().second;
        q.pop();
        if (tauler[xact][yact] == 'B') return true;
        for (int i = 0; i < 4; i++) {
            int xnew = xact + D_X[i];
            int ynew = yact + D_Y[i];
            if (pos_ok(xnew,ynew,f,c)) {
                if (not visitats[xnew][ynew] and not fantasmes(tauler,xnew,ynew,f,c) and tauler[xnew][ynew] != 'X') {   //separo per llegibilitat
                    q.push({xnew,ynew});
                    visitats[xnew][ynew] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    int f, c;
    while (cin >> f >> c) {
        VVC tauler(f,vector<char>(c));
        VVB visitats(f,vector<bool>(c,false));
        int xini, yini;
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++) {
                cin >> tauler[i][j];
                if (tauler[i][j] == 'P') {
                    xini = i;
                    yini = j;
                }
            }
        }
        if (bfs(tauler, visitats, xini, yini, f, c)) cout << "si" << endl;
        else cout << "no" << endl;

    }
}