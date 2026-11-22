//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

struct Edge {
    int u, v;
};

void solve() {
    int n; cin >> n; cin.ignore();
    int a[n + 1][n + 1] = {};
    for (int i = 1; i <= n; ++i) {
        string s; getline(cin, s);
        stringstream ss(s);
        int x;
        while (ss >> x) {
            a[i][x] = 1;
            a[x][i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[i][j] == 1) {
                cout << i << " " << j << endl;
            }
        }
    }
}
int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}