#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
constexpr char NL = '\n';
using namespace std;

int n;
vector<vector<int>> C;
int Cmin = 1e9;
int FOPT = 1e9;
vector<int> went;
int start = 0;


void next(int passed, int curC, int pos) {
    if (passed == n - 1) {
        if (curC < FOPT) {
            FOPT = curC;
        }
        return;
    }

    int bound = curC + (n - 1 -passed) * Cmin;
    if (bound >= FOPT) {
        return;
    } 

    for (int v = 0; v < n; ++v) {
        if (!went[v] && pos != v) { 
            went[v] = true;
            next(passed + 1, curC + C[pos][v], v);         
            went[v] = false;
        }
    }
}


int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        Cmin = 1e9;
        FOPT = 1e9;

        cin >> n;
        C.clear();
        C.resize(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> C[i][j];
                if (i != j && C[i][j] < Cmin)  {
                    Cmin = min(C[i][j], Cmin);
                }
            }
        }

        for (int start = 0; start < n; ++start) {
            went.assign(n, false);
            went[start] = true;
            next(0, 0, start);
        }

        cout << FOPT << NL;
    }
    return 0;
}