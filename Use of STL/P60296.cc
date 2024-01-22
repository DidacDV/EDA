#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2) {
    if (p1.second > p2.second) return true;
    else if (p2.second > p1.second) return false;
    else {
        if (p1.first >= p2.first) return false;
        return true;
    }
}

int main() {
    unordered_map<string, pair<bool,int>> players;  //name, <logged, elo>
    string op;
    while (cin >> op) {
        if (op == "LOGIN") {
            string a;
            cin >> a;
            auto it = players.find(a);
            if (it != players.end()) players[a].first = true;
            else {
                players[a].first = true;
                players[a].second = 1200;
            }
        }
        else if (op == "LOGOUT") {
            string a;
            cin >> a;
            auto it = players.find(a);
            if (it != players.end()) players[a].first = false;
        }
        else if (op == "GET_ELO") {
            string a;
            cin >> a;
            cout << a << ' ' << players[a].second << endl;

        }
        else if (op == "PLAY") {
            string p1, p2;
            cin >> p1 >> p2;
            auto ip1 = players.find(p1);
            auto ip2 = players.find(p2);
            if (ip1 == players.end() or ip2 == players.end() or not ip1->second.first or not ip2->second.first) {
                cout << "jugador(s) no connectat(s)" << endl;
            }
            else {
                ip1->second.second += 10;
                if (ip2->second.second > 1200) ip2->second.second -= 10;
            }
        }
    }
    
    vector<pair<string, int>> v(players.size());
    auto it = players.begin();
    int i = 0;
    for(int i = 0; i < v.size(); ++i) {
        v[i].first = it->first;
        v[i].second = it->second.second;
        ++it;
    }

    sort(v.begin(), v.end(), comp);
    cout << endl << "RANKING" << endl;
    for (int i = 0; i < v.size(); ++i) cout << v[i].first << ' ' << v[i].second << endl;
}