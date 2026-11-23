//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
#define pii pair<int, int>

int v, e, m;
vector<vector<int>> a;
vector<int> color;

bool ok(int ver, int c) {
    for (int dest = 1; dest <= v; ++dest) {
        if (a[ver][dest] && color[dest] == c) {
            return false;
        }
    }
    return true;
}

bool bt(int ver) {
    if (ver > v) return true;
    for (int c = 1; c <= m; ++c) {
        if (ok(ver, c)) {   
            color[ver] = c;
            if (bt(ver + 1)) return true;
            color[ver] = 0;
        }
    }
    return false;
}

void solve() {
    cin >> v >> e >> m;
    a.clear(), a.assign(v + 1, vector<int>(v + 1, 0));
    color.clear(), color.resize(v + 5);
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            cout << "NO";
            return;
        }
        a[u][v] = 1;
        a[v][u] = 1;
    }    
    if (bt(1)) cout << "YES";
    else cout << "NO";     
}
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}