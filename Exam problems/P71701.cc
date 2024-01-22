#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N_DIR = 4;

const vector<int> D_X = {1,0,-1,0,1,-1,1,-1};
const vector<int> D_Y = {0,1,0,-1,1,-1,-1,1};

void escriu_t (vector<vector<char>> &t) {
	for (int i=0; i < t.size(); ++i) {
		for (int j=0; j < t[0].size(); ++j) {
			cout << t[i][j];
		}
		cout << endl;
	}
	cout << "----------" << endl;
}



bool ok(int i, int j, int n, int m) {
    return i - 1 >= 0 and j - 1 >= 0 and i  + 1< n and j + 1 < m;
}

bool comprovar_posicions_disponibles (int i, int j, vector<vector<char>>& tauler) {
	if (tauler[i][j] == 'K') return false;
	else if (i-1 >= 0 and tauler[i-1][j] == 'K') return false;
	else if (i+1 < tauler.size() and tauler[i+1][j] == 'K') return false;
	else if (j-1 >= 0 and tauler[i][j-1] == 'K') return false;
	else if (j+1 < tauler.size() and tauler[i][j+1] == 'K') return false;
	else if (i-1 >= 0 and j-1 >= 0 and tauler[i-1][j-1] == 'K') return false;
	else if (i+1 < tauler.size() and j-1 >= 0 and tauler[i+1][j-1] == 'K') return false;
	else if (i+1 < tauler.size() and j-1 >= 0 and tauler[i+1][j-1] == 'K') return false;
	else if (i-1 >= 0 and j+1 < tauler.size() and tauler[i-1][j+1] == 'K') return false;
	else return true;
}
void reis(vector<vector<char>> &t,int n,int r,int i, int y,int k) {
    
    if (k == r) escriu_t(t);

    
    
    else { 
        bool primer = true;
        for(int x = i; x < n; ++x) {
            for (int j = 0;j < n; j++) {
                if(primer) primer = false, j = y;
                if (comprovar_posicions_disponibles(x,j,t)) {
                    t[x][j] = 'K';
                    reis(t,n,r,x,j,k+1);
                    t[x][j] = '.';
                }
            }
        }
    }
}

int main() {

    int n,r;
    cin >> n >> r;
    vector<vector<char>> t(n,vector<char>(n,'.'));

    reis(t,n,r,0,0,0);
}